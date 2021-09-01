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
#include <sys/wait.h>

struct packet
{
    int len;
    char buf[1024];
};

#define ERR_EXIT(m) \
        do \
        {   \
            perror(m);  \
            exit(EXIT_FAILURE); \
        } while(0);


ssize_t readn(int fd, void *buf, size_t count)
{
    size_t nleft = count;   // 剩余字节数
    ssize_t nread;
    char *bufp = (char*) buf;

    while (nleft > 0) {
        nread = read(fd, bufp, nleft);
        if (nread < 0) {
            if (errno == EINTR) {
                continue;
            }
            return  -1;
        } else if (nread == 0) {
            return count - nleft;
        }

        bufp += nread;
        nleft -= nread;
    }
    return count;
}

ssize_t writen(int fd, const void *buf, size_t count)
{
    size_t nleft = count;
    ssize_t nwritten;
    char* bufp = (char*)buf;

    while (nleft > 0) {
        if ((nwritten = write(fd, bufp, nleft)) < 0) {
            if (errno == EINTR) {
                continue;
            }
            return -1;
        }
        else if (nwritten == 0) {
            continue;
        }
        bufp += nwritten;
        nleft -= nwritten;
    }
    return count;
}

ssize_t recv_peek(int fd, char *buf, size_t count) {
    while(1) {
        int ret = recv(fd, buf, count, MSG_PEEK);
        if (ret < 0 && errno == EINTR) {
            continue;
        }
        return ret;
    } 
}

ssize_t readline(int fd, void *buf, size_t maxcount) {
    char* pbuf = (char*)buf;
    int nread;
    int ret;
    int left = maxcount;
    while (left) {
        ret = recv_peek(fd, pbuf, left);
        if (nread == -1) {
            return ret;
        } else if (ret == 0) {
            printf("clinet close\n");
            return ret;
        }
        nread = ret;
        for (int i = 0; i < nread; ++i) {
            if (pbuf[i] == '\n') {
                ret = read(fd, pbuf, i+1);
                if (ret != i + 1) {
                    exit(EXIT_FAILURE);
                }
                return ret;
            }
        }   

        if (nread > left) {
            exit(EXIT_FAILURE);
        }
        left -= nread;
        ret = readn(fd, pbuf, nread);
        if (ret != nread) {
            exit(EXIT_FAILURE);
        }
        pbuf += nread;
    }
    return -1;
}

void do_service(int connfd) {
    //struct packet recvbuf;
    char recvbuf[1024];
    int n;
    while(1) {
        
        memset(&recvbuf, 0, sizeof(recvbuf));

        int ret = readline(connfd, recvbuf, 1024);
        if (ret == -1) {
            ERR_EXIT("readline");
        }
        else if (ret == 0) {
            printf("client close\n");
            break;
        }
        
        fputs(recvbuf, stdout);
        writen(connfd, recvbuf, strlen(recvbuf));
    }
}

void sigchld_handler(int sig) {
    while(waitpid(-1, NULL, WNOHANG)) 
        ;
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
    signal(SIGCHLD, sigchld_handler);
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
