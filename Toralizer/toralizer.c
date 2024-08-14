/* Toralizer.c */
#include "toralizer.h"

// Function to create a proxy request
Request *create_proxy_request(const char *destination_address, const int destination_port)
{
    Request *proxy_request;

    // Allocate memory for the new request
    proxy_request = (Request *)malloc(REQUEST_SIZE);
    if (proxy_request == NULL)
    {
        perror("Error: Memory allocation failed");
        return NULL;
    }

    // Initialize the request fields
    proxy_request->version = 4;
    proxy_request->command = 1;
    proxy_request->destination_port = htons(destination_port);
    proxy_request->destination_address = inet_addr(destination_address);
    strncpy((char *)proxy_request->userid, USERNAME, 8);

    return proxy_request;
}

int main(int argc, char *argv[])
{
    // Check for valid input arguments
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <PORT>\n", argv[0]);
        return -1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);
    int socket_fd;
    struct sockaddr_in server_address;
    Request *proxy_request;
    Response *proxy_response;
    char response_buffer[RESPONSE_SIZE];
    int connection_success;
    char http_request_buffer[512];

    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0)
    {
        perror("Error: Socket creation failed");
        return -1;
    }

    // Setup the server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);

    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, ip_address, &server_address.sin_addr) <= 0)
    {
        perror("Error: Invalid IP address / Address not supported");
        close(socket_fd);
        return -1;
    }

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Error: Connection failed");
        close(socket_fd);
        return -1;
    }

    printf("Connected to %s:%d\n", ip_address, port_number);

    // Create the proxy request
    proxy_request = create_proxy_request(ip_address, port_number);
    if (proxy_request == NULL)
    {
        fprintf(stderr, "Error: Proxy request creation failed\n");
        close(socket_fd);
        return -1;
    }

    // Send the proxy request
    ssize_t bytes_sent = write(socket_fd, proxy_request, REQUEST_SIZE);
    if (bytes_sent < 0)
    {
        perror("Error: Write failed");
        free(proxy_request);
        close(socket_fd);
        return -1;
    }

    printf("Proxy request sent successfully (%ld bytes)\n", bytes_sent);

    // Read the response from the proxy
    memset(response_buffer, 0, RESPONSE_SIZE);
    ssize_t bytes_received = read(socket_fd, response_buffer, RESPONSE_SIZE);
    if (bytes_received < 0)
    {
        perror("Error: Read failed");
        free(proxy_request);
        close(socket_fd);
        return -1;
    }

    proxy_response = (Response *)response_buffer;
    connection_success = (proxy_response->command == 90);

    if (!connection_success)
    {
        fprintf(stderr, "Unable to traverse the proxy, error code: %d\n", proxy_response->command);
        free(proxy_request);
        close(socket_fd);
        return -1;
    }

    printf("Successfully connected to the proxy at %s:%d\n", ip_address, port_number);

    // Prepare and send an HTTP request through the proxy
    memset(http_request_buffer, 0, sizeof(http_request_buffer));
    snprintf(http_request_buffer, sizeof(http_request_buffer),
             "HEAD / HTTP/1.0\r\n"
             "Host: %s:%d\r\n\r\n",
             ip_address, port_number);
    write(socket_fd, http_request_buffer, strlen(http_request_buffer));

    // Read the HTTP response
    memset(http_request_buffer, 0, sizeof(http_request_buffer));
    read(socket_fd, http_request_buffer, sizeof(http_request_buffer) - 1);
    printf("'%s'", http_request_buffer);

    // Close the socket and free allocated memory
    close(socket_fd);
    free(proxy_request);

    return 0;
}
