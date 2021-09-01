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
#include <sys/select.h>

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
            return -1;
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

void echo_cli(int connfd) {
    fd_set rset;
    FD_ZERO(&rset);
    int nready;
    int maxfd;
    int fd_stdin = fileno(stdin);
    if(fd_stdin > connfd) {
        maxfd = fd_stdin;
    } else {
        maxfd = connfd;
    }

    char recvbuf[1024] = {0};
    char sendbuf[1024] = {0};
    int stdineof = 1;
    while(1) {
        if (stdineof) {
            FD_SET(fd_stdin, &rset);
        }
            
        FD_SET(connfd, &rset);
        nready = select(maxfd+1, &rset, NULL, NULL, NULL);
        if (nready == -1) {
            ERR_EXIT("select");
        }
        if (nready == 0) 
            continue;
    
        if (FD_ISSET(connfd, &rset)) {
            int ret = readline(connfd, recvbuf, 1024);
            if (ret == -1) {
                ERR_EXIT("readline");
            } else if (ret == 0) {
                printf("server close\n");
                break;
            }
        
            fputs(recvbuf, stdout);
            memset(&recvbuf, 0, sizeof(recvbuf));

        }

        if (FD_ISSET(fd_stdin, &rset)) {
            if (fgets(sendbuf, sizeof sendbuf, stdin) == NULL) {
                stdineof = 0;
                shutdown(connfd, SHUT_WR);
                
            } else {
                writen(connfd, sendbuf, strlen(sendbuf)); 
            }
            
        }
    }
}

int main(int argc, char const *argv[]) {
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

    echo_cli(connfd);
    //close(connfd);
    return 0;
}
