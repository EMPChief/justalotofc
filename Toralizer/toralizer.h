/* toralizer.h */
#ifndef TORALIZER_H
#define TORALIZER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dlfcn.h>

// Proxy server defaults
#define PROXY_IP "127.0.0.1"
#define PROXY_PORT 9050

// Size constants for request and response structures
#define REQUEST_SIZE sizeof(struct ProxyRequest)
#define RESPONSE_SIZE sizeof(struct ProxyResponse)

// Default username for the proxy connection
#define USERNAME "toraliz"

// Type definitions for fixed-width data types
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;

// Structure to hold a proxy request
typedef struct ProxyRequest
{
    uint8_t version;              // Version of the request (e.g., SOCKS version)
    uint8_t command;              // Command type (e.g., CONNECT)
    uint16_t destination_port;    // Destination port number (in network byte order)
    uint32_t destination_address; // Destination IP address (in network byte order)
    unsigned char userid[8];      // User ID (null-terminated if shorter than 8 bytes)
} ProxyRequest;

// Structure to hold a proxy response
typedef struct ProxyResponse
{
    uint8_t version;              // Version of the response (e.g., SOCKS version)
    uint8_t command;              // Command type (e.g., SUCCESS, FAILURE)
    uint16_t destination_port;    // Destination port number (in network byte order)
    uint32_t destination_address; // Destination IP address (in network byte order)
} ProxyResponse;

// Function prototypes
ProxyRequest *create_proxy_request(const char *destination_ip, int destination_port);
int connect(int socket_file_descriptor, const struct sockaddr *address, socklen_t address_length);

#endif // TORALIZER_H