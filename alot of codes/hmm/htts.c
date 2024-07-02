#include <ctype.h>
#include <errno.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define HTTP_PROTOCOL_11 "HTTP/1.1"
#define HEADER_SEP ": "
#define CRLF "\r\n"

static char *directory_name;

typedef struct header {
    char *name;
    char *value;
} header;

typedef struct headers_data {
    int length;
    header **headers;
} headers_data;

typedef struct request_data {
    char *method;
    char *path;
    char *body;
    headers_data *headers;
} request_data;

char **get_str_tokens(char *str, char *delim);
int str_starts_with(const char *str, char *searchStr);
char *build_header(const char *name, const char *val);
char *build_start_line(int status, const char *status_text);
void parse_request_buffer(char *buff, request_data *result);

void *http_handler(void *args);

int main(int argc, char **argv) {
    // Parse command-line arguments
    for (int i = 1; i < argc; ++i) {
        if (strcmp("--directory", argv[i]) == 0 && argc > i + 1) {
            directory_name = argv[i + 1];
        }
    }

    // Disable output buffering
    setbuf(stdout, NULL);

    // Initialize server socket
    int server_fd, client_addr_len;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Socket creation failed: %s...\n", strerror(errno));
        return 1;
    }

    // Enable SO_REUSEPORT to avoid 'Address already in use' errors
    int reuse = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) < 0) {
        printf("SO_REUSEPORT failed: %s \n", strerror(errno));
        return 1;
    }

    // Configure server address
    struct sockaddr_in serv_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(4221),
        .sin_addr = {htonl(INADDR_ANY)},
    };

    // Bind socket to the specified address
    if (bind(server_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) != 0) {
        printf("Bind failed: %s \n", strerror(errno));
        return 1;
    }

    // Start listening for incoming connections
    int connection_backlog = 5;
    if (listen(server_fd, connection_backlog) != 0) {
        printf("Listen failed: %s \n", strerror(errno));
        return 1;
    }

    printf("Waiting for a client to connect...\n");

    // Accept and handle client connections
    struct sockaddr_in client_addr;
    pthread_t tid;
    while (1) {
        client_addr_len = sizeof(client_addr);
        int client = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client < 0) {
            break;
        }

        printf("Client connected\n");

        // Create a new thread to handle client request
        pthread_create(&tid, NULL, http_handler, (void *)client);
    }

    // Close server socket
    close(server_fd);
    return 0;
}
void *http_handler(void *args) {
    char *response;
    char buffer[255];
    int client = (int)args;
    
    // Read request from client
    read(client, buffer, sizeof(buffer));
    printf("Received request:\n%s", buffer);
    
    // Parse the request
    request_data *request = malloc(sizeof(request_data));
    parse_request_buffer(buffer, request);

    // Handle GET and POST requests
    if (strcmp(request->method, "GET") == 0 && str_starts_with(request->path, "/files")) {
        // GET /files/{filename}
        char *file_name = get_str_tokens(request->path, "/")[1];
        size_t file_path_size = strlen(directory_name) + 1 + strlen(file_name) + 1;
        char *file_path = calloc(sizeof(char), file_path_size);
        strcat(file_path, directory_name);
        strcat(file_path, "/");
        strcat(file_path, file_name);

        // Read file contents and prepare response
        char *file_contents = NULL;
        if (access(file_path, 0) == 0) {
            FILE *file = fopen(file_path, "rb");
            fseek(file, 0, SEEK_END);
            long file_length = ftell(file);
            file_contents = malloc(sizeof(char) * file_length + 1);
            fseek(file, 0, SEEK_SET);
            fread(file_contents, file_length, 1, file);
            fclose(file);
            file_contents[file_length] = '\0';

            char *res_start = build_start_line(200, "OK");
            char *content_type_header = build_header("Content-Type", "application/octet-stream");
            char *content_length_header_value = malloc(32 * sizeof(char));
            snprintf(content_length_header_value, 32, "%lu", file_length);
            char *content_length_header = build_header("Content-Length", content_length_header_value);
            
            size_t res_size = strlen(res_start) + strlen(content_type_header) + strlen(content_length_header) + strlen(CRLF) + strlen(file_contents) + 1;
            char *res_local = calloc(sizeof(char), res_size);
            strcat(res_local, res_start);
            strcat(res_local, content_type_header);
            strcat(res_local, content_length_header);
            strcat(res_local, CRLF);
            strcat(res_local, file_contents);
            response = res_local;
        } else {
            response = "HTTP/1.1 404 Not Found\r\n\r\n";
        }
    } else if (strcmp(request->method, "POST") == 0 && str_starts_with(request->path, "/files")) {
        // POST /files/{filename}
        char *file_name = get_str_tokens(request->path, "/")[1];
        size_t file_path_size = strlen(directory_name) + 1 + strlen(file_name) + 1;
        char *file_path = calloc(sizeof(char), file_path_size);
        strcat(file_path, directory_name);
        strcat(file_path, "/");
        strcat(file_path, file_name);

        // Write request body to file
        char *file_contents = strdup(request->body);
        FILE *file = fopen(file_path, "w");
        fputs(file_contents, file);
        fclose(file);

        // Prepare response
        char *res_start = build_start_line(201, "Created");
        response = calloc(sizeof(char), strlen(res_start) + strlen(CRLF) + 1);
        strcat(response, res_start);
        strcat(response, CRLF);
    } else if (str_starts_with(request->path, "/user-agent")) {
        // /user-agent endpoint
        char *user_agent_header_value = NULL;
        for (int i = 0; i < request->headers->length; ++i) {
            if (strcmp(request->headers->headers[i]->name, "User-Agent") == 0) {
                user_agent_header_value = request->headers->headers[i]->value;
                break;
            }
        }
        char *content_type_header = build_header("Content-Type", "text/plain");
        char *content_length_header;

        if (user_agent_header_value != NULL) {
            char *content_length_header_value = malloc(strlen(user_agent_header_value) * sizeof(char));
            snprintf(content_length_header_value, strlen(user_agent_header_value), "%lu", strlen(user_agent_header_value));
            content_length_header = build_header("Content-Length", content_length_header_value);
        } else {
            content_length_header = build_header("Content-Length", "0");
        }

        char *res_start = build_start_line(200, "OK");
        size_t res_size = strlen(res_start) + strlen(content_type_header) + strlen(content_length_header) + strlen(CRLF);
        
        if (user_agent_header_value != NULL) {
            res_size += strlen(user_agent_header_value);
        }
        res_size += 1;
        
        char *res_local = calloc(sizeof(char), res_size);
        strcat(res_local, res_start);
        strcat(res_local, content_type_header);
        strcat(res_local, content_length_header);
        strcat(res_local, CRLF);
        
        if (user_agent_header_value != NULL) {
            strcat(res_local, user_agent_header_value);
        }
        
        response = res_local;
    } else if (str_starts_with(request->path, "/echo")) {
        // /echo endpoint
        char *echo_message = get_str_tokens(request->path, "/")[1];
        char *content_type_header = build_header("Content-Type", "text/plain");
        char content_length_value_str[32];
        snprintf(content_length_value_str, sizeof(content_length_value_str), "%lu", strlen(echo_message));
        char *content_length_header = build_header("Content-Length", content_length_value_str);

        char *res_start = build_start_line(200, "OK");
        size_t res_size = strlen(res_start) + strlen(content_type_header) + strlen(content_length_header) + strlen(CRLF) + strlen(echo_message) + 1;
        char *res_local = calloc(sizeof(char), res_size);
        
        strcat(res_local, res_start);
        strcat(res_local, content_type_header);
        strcat(res_local, content_length_header);
        strcat(res_local, CRLF);
        strcat(res_local, echo_message);
        
        response = res_local;
    } else if (strcmp("/", request->path) != 0) {
        // Path not found
        response = "HTTP/1.1 404 Not Found\r\n\r\n";
    } else {
        // Default response
        response = "HTTP/1.1 200 OK\r\n\r\n";
    }

    // Send response to client
    write(client, response, strlen(response));

    // Clean up allocated memory
    free(request);
    free(response);
}

void parse_request_buffer(char *buffer, request_data *result) {
    // Parse HTTP request buffer into request_data structure
    char *rest = strdup(buffer);
    memset(result, 0, sizeof(request_data));

    // Extract HTTP method
    size_t method_len = strcspn(rest, " ");
    result->method = calloc(sizeof(char), method_len + 1);
    memcpy(result->method, rest, method_len);
    rest += method_len + 1;

    // Extract path
    size_t path_len = strcspn(rest, " ");
    result->path = calloc(sizeof(char), path_len + 1);
    memcpy(result->path, rest, path_len);
    rest += path_len + 1;

    // Skip version and CRLF
    rest += strcspn(rest, CRLF) + 2;

    // Parse headers
    int headers_len = 0;
    header **headers = malloc(0);
    while (rest[0] != '\r' || rest[1] != '\n') {
        headers_len++;
        headers = realloc(headers, sizeof(header *) * headers_len);
        size_t name_len = strcspn(rest, ":");
        headers[headers_len - 1] = malloc(sizeof(header));
        headers[headers_len - 1]->name = calloc(sizeof(char), name_len + 1);
        memcpy(headers[headers_len - 1]->name, rest, name_len);
        rest += name_len + 1;

        while (isspace(*rest))
            rest++;

        size_t value_len = strcspn(rest, CRLF);
        headers[headers_len - 1]->value = calloc(sizeof(char), value_len + 1);
        memcpy(headers[headers_len - 1]->value, rest, value_len);
        rest += value_len + 2;
    }

    result->headers = malloc(sizeof(headers_data));
    result->headers->headers = headers;
    result->headers->length = headers_len;

    // Extract body
    result->body = strdup(rest) + 2;
}

char **get_str_tokens(char *str, char *delim) {
    // Tokenize string by delimiter
    char **tokens = malloc(5 * sizeof(char *));
    char *token;
    char *rest = strdup(str);
    int i = 0;
    
    while ((token = strtok_r(rest, delim, &rest))) {
        tokens[i] = calloc(sizeof(char), strlen(token) + 1);
        strcpy(tokens[i], token);
        i++;
    }

    return tokens;
}

int str_starts_with(const char *str, char *searchStr) {
    // Check if string starts with a substring
    if (strncmp(str, searchStr, strlen(searchStr)) == 0)
        return 1;
    else
        return 0;
}

char *build_header(const char *name, const char *val) {
    // Construct HTTP header string
    size_t header_size = strlen(name) + strlen(HEADER_SEP) + strlen(val) + strlen(CRLF) + 1;
    char *header_str = calloc(sizeof(char), header_size);
    strcat(header_str, name);
    strcat(header_str, HEADER_SEP);
    strcat(header_str, val);
    strcat(header_str, CRLF);
    return header_str;
}

char *build_start_line(int status, const char *status_text) {
    // Construct HTTP status line
    char status_num_str[6];
    snprintf(status_num_str, sizeof(status_num_str), "%d", status);
    size_t start_line_size = strlen(HTTP_PROTOCOL_11) + 1 + strlen(status_num_str) + 1 + strlen(status_text) + strlen(CRLF) + 1;
    char *start_line = calloc(sizeof(char), start_line_size);
    strcat(start_line, HTTP_PROTOCOL_11);
    strcat(start_line, " ");
    strcat(start_line, status_num_str);
    strcat(start_line, " ");
    strcat(start_line, status_text);
    strcat(start_line, CRLF);
    return start_line;
}
