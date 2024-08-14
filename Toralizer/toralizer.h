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
struct ProxyRequest
{
    uint8_t version;              // Version of the request (e.g., SOCKS version)
    uint8_t command;              // Command type (e.g., CONNECT)
    uint16_t destination_port;    // Destination port number (in network byte order)
    uint32_t destination_address; // Destination IP address (in network byte order)
    unsigned char userid[8];      // User ID (null-terminated if shorter than 8 bytes)
};
typedef struct ProxyRequest Request;

// Structure to hold a proxy response
struct ProxyResponse
{
    uint8_t version;              // Version of the response (e.g., SOCKS version)
    uint8_t command;              // Command type (e.g., SUCCESS, FAILURE)
    uint16_t destination_port;    // Destination port number (in network byte order)
    uint32_t destination_address; // Destination IP address (in network byte order)
};
typedef struct ProxyResponse Response;

// Function prototypes
Request *create_proxy_request(const char *destination_address, const int destination_port);
int main(int argc, char *argv[]);

#endif // TORALIZER_H
