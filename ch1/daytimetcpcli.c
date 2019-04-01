#include "unp.h"

int
main(int argc, char **argv)
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if (argc != 2)
        err_quit("usage: daytimetcpcli <IPaddress>");

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9999);
    
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    Connect(sockfd, (SA *)&servaddr, sizeof(servaddr));

    int count = 0;
    while ( (n = Read(sockfd, recvline, MAXLINE)) > 0 )
    {
        recvline[n] = 0;
        count ++;
        Fputs(recvline, stdout);
    }

    printf("Totol read times: %d\n", count);

    exit(0);
}
