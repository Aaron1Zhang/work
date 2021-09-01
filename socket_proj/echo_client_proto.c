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
    
    struct packet recvbuf;
    struct packet sendbuf;
    memset(&recvbuf, 0, sizeof(recvbuf));
    memset(&sendbuf, 0, sizeof(sendbuf));
    int n = 0;
    while (fgets(sendbuf.buf, sizeof(sendbuf.buf), stdin) != NULL) {
        n = strlen(sendbuf.buf);
        sendbuf.len = htonl(n);
        writen(connfd, &sendbuf, 4 + n);

        int ret = readn(connfd, &recvbuf.len, 4);
        if (ret == -1) {
            ERR_EXIT("read");
        } else if (ret < 4) {
            printf("server close\n");
            break;
        }

        n = ntohl(recvbuf.len);
        ret = readn(connfd, &recvbuf.buf, n);
        if (ret == -1) {
            ERR_EXIT("read");
        } else if (ret < n) {
            printf("server close\n");
            break;
        }
        fputs(recvbuf.buf, stdout);
        memset(&recvbuf, 0, sizeof(recvbuf));
        memset(&sendbuf, 0, sizeof(sendbuf));

    }
    close(connfd);
    return 0;
}
