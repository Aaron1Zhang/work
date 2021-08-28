#include <iostream>
#include "ChartServer.h"
#include "ChartService.h"
#include <muduo/net/InetAddress.h>
#include <signal.h>
void resetHandler(int) {
    ChartService::instance()->serverCloseException();
    exit(0);
}

int main(int argc, char const *argv[])
{

    signal(SIGINT, resetHandler);
    EventLoop loop;
    InetAddress listenAddr("127.0.0.1", 6000);
    
    ChartServer server(&loop, listenAddr, "ChartServer");
    server.start();
    loop.loop();
    return 0;
}
