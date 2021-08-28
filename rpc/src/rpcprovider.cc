#include "rpcprovider.h"
#include "mprpcapplication.h"
#include "mprpcconfig.h"
#include <string>


void RpcProvider::notifyService(::google::protobuf::Service* service) {

}

void RpcProvider::Run() {

    auto config = MprpcApplication::getInstance().getConfig();
    std::string ip_str = config.Load("rpcserverip");
    unsigned short port = atoi(config.Load("rpcserverport").c_str());
    muduo::net::InetAddress addr(ip_str, port);
    muduo::net::TcpServer server(&loop_, addr, "RpcProvider", 
                                muduo::net::TcpServer::Option::kReusePort);
    server.setConnectionCallback(std::bind(&RpcProvider::onConnection, this, std::placeholders::_1));
    server.setMessageCallback(std::bind(&RpcProvider::onMessage, this, 
                            std::placeholders::_1,
                            std::placeholders::_2, 
                            std::placeholders::_3));

    server.setThreadNum(4);
    server.start();
    loop_.loop();
}

void RpcProvider::onConnection(const muduo::net::TcpConnectionPtr&) {

}
void RpcProvider::onMessage(const muduo::net::TcpConnectionPtr&,muduo::net::Buffer*, muduo::Timestamp) {

}