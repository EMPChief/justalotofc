#ifndef TORALIZER_H
#define TORALIZER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PROXY_IP "127.0.0.1"
#define PROXY_PORT 9050

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

struct proxy_request{
    int8 version;
    int8 command;
    int16 destination_port;
    int32 destination_address;
    unsigned char userid[8];
};
typedef struct proxy_request Request;

struct proxy_response{
    int8 version;
    int8 command;
    int16 destination_port;
    int32 destination_address;
};
typedef struct proxy_response Response;


#endif
