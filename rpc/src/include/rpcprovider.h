#pragma once
#include "google/protobuf/service.h"
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/base/Timestamp.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <functional>
#include <string>
#include <unordered_map>
#include <google/protobuf/descriptor.h>

class RpcProvider {
public:
    void notifyService(::google::protobuf::Service* service);
    void Run();

private:
    struct ServerInfo {
        google::protobuf::Service* m_service;
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor*> m_methodMap;
    };

    std::unordered_map<std::string, ServerInfo> m_serviceMap;

    muduo::net::EventLoop loop_;

    void onConnection(const muduo::net::TcpConnectionPtr&);

    void onMessage(const muduo::net::TcpConnectionPtr&, muduo::net::Buffer*, muduo::Timestamp);

    void sendRpcResponce(const muduo::net::TcpConnectionPtr&, google::protobuf::Message*);
};
