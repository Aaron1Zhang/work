#include "rpcprovider.h"
#include "mprpcapplication.h"
#include "mprpcconfig.h"
#include "rpcheader.pb.h"
#include <muduo/base/Logging.h>

void RpcProvider::notifyService(::google::protobuf::Service* service) {
    ServerInfo service_info;
    auto pserviceDesc = service->GetDescriptor();
    std::string service_name = pserviceDesc->name();
    int method_cnt = pserviceDesc->method_count();
    LOG_INFO << "service_name:" <<  service_name << "\n";

    for (int i = 0 ; i < method_cnt; ++i) {
        auto pmethodDesc = pserviceDesc->method(i);
        std::string method_name = pmethodDesc->name();
        service_info.m_methodMap.insert({method_name, pmethodDesc});

        LOG_INFO << "methd_name : " << method_name << "\n";
    }
    service_info.m_service = service;
    m_serviceMap.insert({service_name, service_info});

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

void RpcProvider::onConnection(const muduo::net::TcpConnectionPtr& conn) {
    if (!conn->connected()) {
        conn->shutdown();
    }
}
void RpcProvider::onMessage(const muduo::net::TcpConnectionPtr&,muduo::net::Buffer* buffer, muduo::Timestamp) {
    std::string recv_buf = buffer->retrieveAllAsString();

    uint32_t header_size = 0;
    recv_buf.copy((char*)&header_size, 4, 0);
    std::string rpc_header_str = recv_buf.substr(4, header_size);

    mprpc::RpcHeader rpcHeader;
    uint32_t args_size;
    std::string service_name;
    std::string method_name;
    if (rpcHeader.ParseFromString(rpc_header_str)) {
        auto service_name = rpcHeader.service_name();
        auto method_name = rpcHeader.method_name();
        args_size = rpcHeader.args_size();
    } else {
        std::cout << "rpc_head_str: " << rpc_header_str << "parse failed!" << "\n";
        return;
    }

    std::string args_str = recv_buf.substr(4 + header_size, args_size);
    std::cout << "============================================" << std::endl;
    std::cout << "header_size: " << header_size << std::endl; 
    std::cout << "rpc_header_str: " << rpc_header_str << std::endl; 
    std::cout << "service_name: " << service_name << std::endl; 
    std::cout << "method_name: " << method_name << std::endl; 
    std::cout << "args_str: " << args_str << std::endl; 
    std::cout << "============================================" << std::endl;
}












