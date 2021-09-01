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
        if (ret == -1) {
            return ret;
        } else if (ret == 0) {
           
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

void sigpipe(int sig) {
    printf("recv signal: %d\n", sig);
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
    
    fd_set allset;
    fd_set rset;
    FD_ZERO(&allset);
    FD_ZERO(&rset);
    FD_SET(listen_fd, &allset);
    int maxfd = listen_fd;
    int nready;
    int connfd;
    int client[FD_SETSIZE] = {-1};
    int i;
    int ret;
    while (1) {
        rset = allset;
        nready = select(maxfd + 1, &rset, NULL, NULL, NULL);
        if (nready == -1) {
            if (errno == EINTR) {
                continue;
            }
        }
        if (nready == 0) continue;

        if (FD_ISSET(listen_fd, &rset)) {
            
            if ((connfd = accept(listen_fd, (struct sockaddr*)&peeraddr, &peerlen)) < 0) {
                ERR_EXIT("accpet");
            }
 
            for (i = 0 ; i < FD_SETSIZE; ++i) {
                if (client[i] == -1) {
                    client[i] = connfd;
                    break;
                }
            }
            if (i >= FD_SETSIZE) {
                ERR_EXIT("too many client");
            }

            printf("id = %s, ", inet_ntoa(peeraddr.sin_addr));
            printf("port = %d\n", ntohs(peeraddr.sin_port));
            FD_SET(connfd, &allset);
            if (connfd > maxfd) {
                maxfd = connfd;
            }
            if (--nready == 0) continue;
        }
        // handle other connfd;
        for(i = 0; i < FD_SETSIZE; ++i) {
            connfd = client[i];
            if (connfd == -1) continue;
            if (FD_ISSET(connfd, &rset)) {
                char recvbuf[1024] = {0};
                ret = readline(connfd, recvbuf, sizeof(recvbuf));
                if (ret == -1) {
                    ERR_EXIT("readline");
                }
                if (ret == 0) {
                    printf("clinet close\n");
                    client[i] = -1;
                    FD_CLR(connfd, &allset);
                    close(connfd);
                    continue;
                }
                fputs(recvbuf, stdout);
                writen(connfd, recvbuf, strlen(recvbuf));
                if (--nready <= 0) break;
            }
        }


    }
    close(listen_fd);
    return 0;
}
