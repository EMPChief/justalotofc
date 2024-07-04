/*Toralizer.c*/
#include "toralizer.h"


int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        return -1;
    }

    char *host_ip = argv[1];
    int host_port = atoi(argv[2]);
    int sockfd;
    struct sockaddr_in sockets_a;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket creation failed");
        return -1;
    }

    sockets_a.sin_family = AF_INET;
    sockets_a.sin_port = htons(host_port);
    sockets_a.sin_addr.s_addr = inet_addr(host_ip);
    connect(sockfd, (struct sockaddr *)&sockets_a, sizeof(sockets_a));
    

    return 0;
}
