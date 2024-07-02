/*Toralizer.c*/
#include "toralizer.h"

/*
./Toralizer <ip> <port>
*/

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        return -1;
    }
    char *host_ip = argv[1];
    int host_port = atoi(argv[2]);
    toralize(host_ip, host_port);
    return 0;
}
