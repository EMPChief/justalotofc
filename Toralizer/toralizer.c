/* Toralizer.c */
#include "toralizer.h"

// Function prototype for the overridden connect function
int connect(int socket_file_descriptor, const struct sockaddr *address, socklen_t address_length);

// Function prototype for creating a proxy request
ProxyRequest *create_proxy_request(const char *destination_ip, int destination_port);

// Override the connect function
int connect(int socket_file_descriptor, const struct sockaddr *address, socklen_t address_length)
{
    // Variables initialized at the top
    int (*original_connect_function)(int, const struct sockaddr *, socklen_t) = NULL;
    struct sockaddr_in *ipv4_address = NULL;
    char ip_address_buffer[INET_ADDRSTRLEN] = {0};
    int destination_port = 0;
    ProxyRequest *proxy_request = NULL;
    struct sockaddr_in proxy_server_address = {0};
    ssize_t bytes_sent = 0;
    char response_buffer[RESPONSE_SIZE] = {0};
    ssize_t bytes_received = 0;
    ProxyResponse *proxy_response = NULL;

    // Retrieve the original connect function using dlsym
    original_connect_function = dlsym(RTLD_NEXT, "connect");

    // Cast the address structure to sockaddr_in to extract the IP and port
    ipv4_address = (struct sockaddr_in *)address;
    inet_ntop(AF_INET, &(ipv4_address->sin_addr), ip_address_buffer, INET_ADDRSTRLEN);
    destination_port = ntohs(ipv4_address->sin_port);

    // Create the proxy request
    proxy_request = create_proxy_request(ip_address_buffer, destination_port);
    if (proxy_request == NULL)
    {
        fprintf(stderr, "Error: Proxy request creation failed\n");
        return -1;
    }

    // Prepare the proxy server address structure
    memset(&proxy_server_address, 0, sizeof(proxy_server_address));
    proxy_server_address.sin_family = AF_INET;
    proxy_server_address.sin_port = htons(PROXY_PORT);

    if (inet_pton(AF_INET, PROXY_IP, &proxy_server_address.sin_addr) <= 0)
    {
        perror("Error: Invalid proxy IP address / Address not supported");
        free(proxy_request);
        return -1;
    }

    // Connect to the proxy server
    if (original_connect_function(socket_file_descriptor, (struct sockaddr *)&proxy_server_address, sizeof(proxy_server_address)) < 0)
    {
        perror("Error: Proxy connection failed");
        free(proxy_request);
        return -1;
    }

    printf("Connected to proxy server %s:%d\n", PROXY_IP, PROXY_PORT);

    // Send the proxy request to the server
    bytes_sent = write(socket_file_descriptor, proxy_request, REQUEST_SIZE);
    if (bytes_sent < 0)
    {
        perror("Error: Write to proxy server failed");
        free(proxy_request);
        return -1;
    }

    printf("Proxy request sent successfully (%ld bytes)\n", bytes_sent);

    // Read the response from the proxy
    memset(response_buffer, 0, RESPONSE_SIZE);
    bytes_received = read(socket_file_descriptor, response_buffer, RESPONSE_SIZE);
    if (bytes_received < 0)
    {
        perror("Error: Read from proxy server failed");
        free(proxy_request);
        return -1;
    }

    proxy_response = (ProxyResponse *)response_buffer;
    if (proxy_response->command != 90)
    {
        fprintf(stderr, "Proxy server connection failed with error code: %d\n", proxy_response->command);
        free(proxy_request);
        return -1;
    }

    printf("Successfully connected to the destination via the proxy\n");

    // Free the proxy request
    free(proxy_request);

    // Return success
    return 0;
}

// Function to create a proxy request
ProxyRequest *create_proxy_request(const char *destination_ip, int destination_port)
{
    // Variables initialized at the top
    ProxyRequest *proxy_request = NULL;

    // Allocate memory for the proxy request
    proxy_request = (ProxyRequest *)malloc(REQUEST_SIZE);
    if (proxy_request == NULL)
    {
        perror("Error: Memory allocation failed");
        return NULL;
    }

    // Initialize the proxy request
    proxy_request->version = 4;
    proxy_request->command = 1;
    proxy_request->destination_port = htons(destination_port);
    proxy_request->destination_address = inet_addr(destination_ip);
    strncpy((char *)proxy_request->userid, USERNAME, sizeof(proxy_request->userid) - 1);
    proxy_request->userid[sizeof(proxy_request->userid) - 1] = '\0';

    return proxy_request;
}
