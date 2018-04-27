#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFLEN 2048
#define SERVICE_PORT 21234

int main(int argc, char **argv)
{
    struct sockaddr_in myaddr, remaddr;
    int fd, inet, slen=sizeof(remaddr);
    char messagebuf[BUFLEN];
    int recvlen;
    char *server = "172.24.72.94";

    if ((fd=socket(AF_INET, SOCK_DGRAM, 0)) == -1)
        return 0;

    // Set up the network infra
    memset((char *) &myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    myaddr.sin_port = htons(0);

    if (bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0)
    {
        perror("bind failed");
        return 0;
    }

    memset((char *) &remaddr, 0, sizeof(remaddr));
    remaddr.sin_family = AF_INET;
    remaddr.sin_port = htons(SERVICE_PORT);
    if (inet_aton(server, &remaddr.sin_addr) == 0) 
    {
        fprintf(stderr, "inet_aton() failed\n");
        exit(1);
    }

    // Try sending a message to 


    return 0;
}