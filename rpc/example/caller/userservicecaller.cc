#include "user.pb.h"
#include "mprpcapplication.h"
#include "mprpcchannel.h"

int main(int argc, char **argv)
{
    MprpcApplication::Init(argc, argv);
    fixbug::UserServiceRpc_Stub consumer(new MprpcChannel());
    fixbug::LoginRequest request;
    fixbug::LoginResponse response;
    request.set_name("zhang san");
    request.set_password("123456");
    consumer.Login(nullptr, &request, &response, nullptr);
    
    std::cout << "wait reponse...\n";
    if (response.res().errcode() == 0) {
        std::cout << "request succcess\n";
    } else {
        std::cout << "request failed! err msg is: " << response.res().errcode() << "\n";
    }
    return 0;
}
