#include <string>
#include <iostream>
#include "user.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"

using namespace std;

class UserService : public fixbug::UserServiceRpc {
public:
    bool Login(string name, string pwd) {
        cout << "name is: " << name << "\n";
        cout << "pwd is: " << pwd << "\n";
        return true;
    }

    //framework already unserial the request parameter, so this method can hanle this 
    //request and then send back to consumer
    void Login(::google::protobuf::RpcController* controller,
                       const ::fixbug::LoginRequest* request,
                       ::fixbug::LoginResponse* response,
                       ::google::protobuf::Closure* done) 
    {                   
        string name = request->name();
        string pwd = request->password();

        bool res = Login(name, pwd);
        response->set_success(res);
        auto resCode = response->mutable_res();
        resCode->set_errcode(0);
        resCode->set_errmsg("");
        done->Run();
    }

private:


};

int main(int argc, char** argv)
{
    MprpcApplication::Init(argc, argv);
    RpcProvider provider;
    provider.notifyService(new UserService());
    provider.Run();
    return 0;
}
