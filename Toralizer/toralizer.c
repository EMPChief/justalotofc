/*Toralizer.c*/
#include "toralizer.h"

// Function to create a proxy request
Request *create_request(const char *destination_address, const int destination_port)
{
    Request *new_request;

    new_request = malloc(REQUEST_SIZE);
    if (new_request == NULL)
    {
        perror("Error: Memory allocation failed");
        return NULL;
    }

    new_request->version = 4;
    new_request->command = 1;
    new_request->destination_port = htons(destination_port);
    new_request->destination_address = inet_addr(destination_address);
    strncpy((char *)new_request->userid, USERNAME, 8);

    return new_request;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <PORT>\n", argv[0]);
        return -1;
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);
    int socket_fd;
    struct sockaddr_in server_address;
    Request *request;
    Response *response;
    char buffer[RESPONSE_SIZE];
    int success;

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0)
    {
        perror("Error: Socket creation failed");
        return -1;
    }

    // Setup server address struct
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, ip_address, &server_address.sin_addr) <= 0)
    {
        perror("Error: Invalid IP address / Address not supported");
        close(socket_fd);
        return -1;
    }

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Error: Connection failed");
        close(socket_fd);
        return -1;
    }

    printf("Connected to %s:%d\n", ip_address, port);

    // Create the request
    request = create_request(ip_address, port);
    if (request == NULL)
    {
        fprintf(stderr, "Error: Request creation failed\n");
        close(socket_fd);
        return -1;
    }

    // Send the request
    ssize_t bytes_written = write(socket_fd, request, REQUEST_SIZE);
    if (bytes_written < 0)
    {
        perror("Error: Write failed");
        free(request);
        close(socket_fd);
        return -1;
    }

    printf("Request sent successfully (%ld bytes)\n", bytes_written);

    memset(buffer, 0, RESPONSE_SIZE);
    ssize_t bytes_read = read(socket_fd, buffer, RESPONSE_SIZE);
    if (bytes_read < 0)
    {
        perror("Error: Read failed");
        free(request);
        close(socket_fd);
        return -1;
    }

    response = (Response *)buffer;
    success = (response->command == 90);

    if (!success)
    {
        fprintf(stderr, "Unable to traverse the proxy, error code: %d\n", response->command);
        free(request);
        close(socket_fd);
        return -1;
    }

    printf("Successfully connected to the proxy to %s:%d\n", ip_address, port);

    // Close the socket
    close(socket_fd);

    free(request);

    return 0;
}
