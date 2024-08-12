/*toralizer.h*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PROXY_IP "127.0.0.1"
#define PROXY_PORT 9050
#define REQUEST_SIZE sizeof(struct proxy_request)
#define RESPONSE_SIZE sizeof(struct proxy_response)
#define USERNAME "toraliz"

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

// Structure to hold a proxy request
struct proxy_request
{
    int8 version;                 // Version of the request
    int8 command;                 // Command type
    int16 destination_port;       // Destination port number
    int32 destination_address;    // Destination IP address
    unsigned char userid[8];      // User ID
};
typedef struct proxy_request Request;

// Structure to hold a proxy response
struct proxy_response
{
    int8 version;                 // Version of the response
    int8 command;                 // Command type
    int16 destination_port;       // Destination port number
    int32 destination_address;    // Destination IP address
};
typedef struct proxy_response Response;

// Function prototypes
Request *create_request(const char *, const int);
int main(int, char **);
