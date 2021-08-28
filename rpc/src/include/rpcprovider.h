#pragma once
#include "google/protobuf/service.h"
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/base/Timestamp.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <functional>

class RpcProvider {
public:
    void notifyService(::google::protobuf::Service* service);
    void Run();

private:
    muduo::net::EventLoop loop_;
    void onConnection(const muduo::net::TcpConnectionPtr&);
    void onMessage(const muduo::net::TcpConnectionPtr&,
                        muduo::net::Buffer*,
                        muduo::Timestamp);
};
