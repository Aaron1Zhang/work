#ifndef CHARTSERVER_H
#define CHARTSERVER_H
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
using namespace muduo;
using namespace muduo::net;

class ChartServer {
public:
    ChartServer(EventLoop* loop, const InetAddress& listenAddr,
                const string& name);
    void start();
private:
    void onConnection(const TcpConnectionPtr& conn);
    void onMessage(const TcpConnectionPtr& conn, Buffer*, Timestamp);
    TcpServer _server;
    EventLoop* _loop;

};


#endif 
