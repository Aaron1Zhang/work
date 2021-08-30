#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#define ERR_EXIT(m) \
        do \
        {   \
            perror(m);  \
            exit(EXIT_FAILURE); \
        } while(0);

int main(int argc, char const *argv[])
{
    int connfd;
    if ((connfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        ERR_EXIT("socket");
    }
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6667);
    
    if (connect(connfd, (struct sockaddr*)&servaddr, sizeof servaddr) < 0) {
        ERR_EXIT("connect");
    }
    
    char recvbuf[1024];
    char sendbuf[1024];

    while (fgets(sendbuf, sizeof(sendbuf), stdin) != NULL) {
    
        int n = write(connfd, sendbuf, strlen(sendbuf));
       
        if (n <= 0) {
            printf("cant not send mes\n");
        }
        int ret = read(connfd, recvbuf, sizeof recvbuf);
        fputs(recvbuf, stdout);

        bzero(sendbuf, sizeof sendbuf);
        bzero(recvbuf, sizeof recvbuf);
        
    }
  
    close(connfd);
   


    return 0;
}
