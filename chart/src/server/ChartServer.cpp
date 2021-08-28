#include "ChartServer.h"
//#include "json.hpp"
#include <iostream>
#include <functional>
#include <string>
#include <muduo/base/Logging.h>
#include "ChartService.h"

using namespace std;
using namespace placeholders;

ChartServer::ChartServer(EventLoop* loop, const InetAddress& listenAddr,
                const string& name): _server(loop, listenAddr, name, TcpServer::Option::kReusePort), _loop(loop)
{                
    _server.setConnectionCallback(std::bind(&ChartServer::onConnection, this, _1));
    _server.setMessageCallback(std::bind(&ChartServer::onMessage, this, _1, _2, _3));
    _server.setThreadNum(4);
}
   
void ChartServer::start() {
    _server.start();
}

void ChartServer::onConnection(const TcpConnectionPtr& conn) {
    //if the client close abnormal, then delete the user
    if(!conn->connected()) {
        LOG_INFO << "client discoonect!";
        ChartService::instance()->clientCloseException(conn);
        conn->shutdown();
    } 
}

void ChartServer::onMessage(const TcpConnectionPtr& conn, Buffer* inbuf, Timestamp t) {
    string msg = inbuf->retrieveAllAsString();
    ChartService* service = ChartService::instance();
    json js = json::parse(msg);
    auto handler = service->getMsgHandler(js["msgid"].get<int>());
    handler(conn, js, t);
}


    