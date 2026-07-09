#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include 

int main(int c, char **v){

    if (c != 2)
    {
        write(2, "Wrong number of arguments\n", 27);
        return 1;
    }
    int port = atoi(v[1]);
    int fds = socket(AF_INET, SOCK_STREAM, 0);
    if (fds < 0)
    {
        write(2, "Fatal error\n", 13);
        return 1;
    }

    int opt = 1;
    if (setsockopt(fds, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        write(2, "Fatal error\n", 13);
        return 1;
    }
    struct sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr = htonl(IN_LOOPBACK);
}