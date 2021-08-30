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

void do_service(int connfd) {
    char recvbuf[1024];
    
    while(1) {
        
        memset(recvbuf, 0, sizeof(recvbuf));

        int ret = read(connfd, recvbuf, sizeof(recvbuf));
        if (ret == 0) {
            printf("client close\n");
            break;
        }
        else if (ret == -1) {
            ERR_EXIT("read");
        }
        fputs(recvbuf, stdout);
        write(connfd, recvbuf, ret);

    }
}

int main(int argc, char const *argv[])
{
    int listen_fd;
    if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        ERR_EXIT("socket");
    }
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6667);
    
    int sock_reuse = 1;
    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &sock_reuse, sizeof(sock_reuse)) < 0) {
        ERR_EXIT("setsockopt");
    }

    if (bind(listen_fd, (struct sockaddr*)&servaddr, sizeof servaddr) < 0) {
        ERR_EXIT("bind");
    }

    if (listen(listen_fd, SOMAXCONN) < 0) {
        ERR_EXIT("listen");
    }

   
    struct sockaddr_in peeraddr;
    socklen_t peerlen = sizeof(peeraddr);
    pid_t pid;

    while(1) {
        
        int connfd;
        if ((connfd = accept(listen_fd, (struct sockaddr*)&peeraddr, &peerlen)) < 0) {
            ERR_EXIT("accpet");
        }

        printf("id = %s, ", inet_ntoa(peeraddr.sin_addr));
        printf("port = %d\n", ntohs(peeraddr.sin_port));
        pid = fork();

        if (pid == 0) {
            close(listen_fd);
            do_service(connfd);
            exit(EXIT_SUCCESS);
        } else {
            close(connfd);
        }  
    }

    close(listen_fd);
    return 0;
}
