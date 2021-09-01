#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>

#define ERR_EXIT(m) \
        do \
        {   \
            perror(m);  \
            exit(EXIT_FAILURE); \
        } while(0);

//son process send SIGUSER1 signal to main proecss
void handler(int sig) {
    printf("recv sig %d\n", sig);
    exit(EXIT_SUCCESS);
}

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
    
    pid_t pid;
    pid = fork();

    if (pid == 0) {
       
        char recvbuf[1024];
        while(1) {
            int ret = read(connfd, recvbuf, sizeof recvbuf);
            if (ret == 0) {
                printf("peer colse !\n");
                break;
            } else if (ret == -1) {
                ERR_EXIT("read error\n");
            }
            fputs(recvbuf, stdout);
            bzero(recvbuf, sizeof recvbuf);
        }
        kill(getppid(), SIGUSR1);
        exit(EXIT_SUCCESS);
    } else {
        signal(SIGUSR1, handler);
        char sendbuf[1024] = {0};
        while (fgets(sendbuf, sizeof(sendbuf), stdin) != NULL) {
            int n = write(connfd, sendbuf, strlen(sendbuf));
       
            if (n <= 0) {
                printf("cant not send mes\n");
                ERR_EXIT("write");
            }
            bzero(sendbuf, sizeof sendbuf);
        }
    }
    close(connfd);
    return 0;
}
