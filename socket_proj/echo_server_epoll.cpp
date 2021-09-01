#include <iostream>
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
#include <sys/epoll.h>
#include <fcntl.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<struct epoll_event> EventList;

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

void activate_nonblock(int fd) {
    int ret;
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        ERR_EXIT("fcntl");
    }

    flags |= O_NONBLOCK;
    ret = fcntl(fd, F_SETFL, flags);
    if (ret == -1) {
        ERR_EXIT("fcntl");
    }
}

int main(int argc, char const *argv[])
{
    int listenfd;
    if ((listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        ERR_EXIT("socket");
    }

    // 2. 分配套接字地址
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof servaddr);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    // servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // inet_aton("127.0.0.1", &servaddr.sin_addr);

    int on = 1;
    // 确保time_wait状态下同一端口仍可使用
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof on) < 0) {
        ERR_EXIT("setsockopt");
    }

    // 3. 绑定套接字地址
    if (bind(listenfd, (struct sockaddr *) &servaddr, sizeof servaddr) < 0) {
        ERR_EXIT("bind");
    }
    // 4. 等待连接请求状态
    if (listen(listenfd, SOMAXCONN) < 0) {
        ERR_EXIT("listen");
    }
    // 5. 允许连接
    struct sockaddr_in peeraddr;
    socklen_t peerlen;


    // 6. 数据交换
    int nready;
    int connfd;
    int i;
    vector<int> clients;
    int epollfd;
    epollfd = epoll_create1(EPOLL_CLOEXEC); // 创建一个多路复用的实例

    struct epoll_event event;
    event.data.fd = listenfd;
    event.events = EPOLLIN | EPOLLET;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &event);

    EventList events(16);

    while (1) {
        // 等侍注册在epfd上的socket fd的事件的发生，如果发生则将发生的sokct fd和事件类型放入到events数组中
        nready = epoll_wait(epollfd, &*events.begin(), static_cast<int>(events.size()), -1);    // 用于轮询I/O事件的发生
        if (nready == -1) {
            if (errno == EINTR) {
                continue;
            }
            ERR_EXIT("epoll_wait");
        }

        if (nready == 0) {
            continue;
        }

        if ((size_t)nready == events.size()) {
            events.resize(events.size()*2);
        }

        for (i = 0; i < nready; ++i) {
            if (events[i].data.fd == listenfd) {
                peerlen = sizeof(peeraddr);
                connfd = accept(listenfd, (struct sockaddr*)&peeraddr, &peerlen);
                if (connfd == -1) {
                    ERR_EXIT("accept");
                }
                printf("id = %s, ", inet_ntoa(peeraddr.sin_addr));
                printf("port = %d\n", ntohs(peeraddr.sin_port));
                clients.push_back(connfd);
                activate_nonblock(connfd);

                event.data.fd = connfd;
                event.events = EPOLLIN | EPOLLET;
                epoll_ctl(epollfd, EPOLL_CTL_ADD, connfd, &event);

            } else if (events[i].events & EPOLLIN) {
                connfd = events[i].data.fd;
                if (connfd < 0) {
                    continue;
                }
                char recvbuf[1024];
                int ret = readline(connfd, recvbuf, sizeof(recvbuf));
                if (ret == -1) {
                    ERR_EXIT("readline");
                }
                if (ret == 0) {
                    printf("client close\n");
                    close(connfd);

                    event = events[i];
                    epoll_ctl(epollfd, EPOLL_CTL_DEL, connfd, &event);
                    clients.erase(
                            remove_if(clients.begin(), clients.end(), [connfd](int n){return n == connfd;}),
                            clients.end());
                }
                fputs(recvbuf, stdout);
                writen(connfd, recvbuf, strlen(recvbuf));
            }
        }

    }
    // 7. 断开连接
    close(listenfd);
    return 0;
}
