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
    return 0;
}
