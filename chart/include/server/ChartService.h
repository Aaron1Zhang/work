#ifndef CHARTSERVICE_H
#define CHARTSERVICE_H

#include <functional>
#include <iostream>
#include <unordered_map>
#include <muduo/net/TcpConnection.h>
#include <mutex>
#include "json.hpp"
#include "usermodel.h"
#include "offlinemsgmodel.h"
#include "friendmodel.h"
#include "groupmodel.h"
using namespace muduo;
using namespace muduo::net;
using namespace std;
using json = nlohmann::json;

using MsgHandler = function<void(const TcpConnectionPtr& conn, json& js, Timestamp)>;

class ChartService {
public:
    static ChartService* instance();
    void login(const TcpConnectionPtr& conn, json& js, Timestamp time);
    void reg(const TcpConnectionPtr& conn, json& js, Timestamp time);
    void onetone(const TcpConnectionPtr& conn, json& js, Timestamp time);
    void addFriend(const TcpConnectionPtr& conn, json& js, Timestamp time);
    void createGroup(const TcpConnectionPtr &conn, json &js, Timestamp time);
    void addGroup(const TcpConnectionPtr &conn, json &js, Timestamp time);
    void groupChat(const TcpConnectionPtr &conn, json &js, Timestamp time);
    void loginout(const TcpConnectionPtr &conn, json &js, Timestamp time);
    MsgHandler getMsgHandler(int msg_type);
    void clientCloseException(const TcpConnectionPtr& conn);
    void serverCloseException();
private:
    ChartService();
    std::unordered_map<int, MsgHandler> handlers;
    UserModel _userModel;
    OfflineMsgModel _offMsgModel;
    FriendModel _friendModel;
    GroupModel _groupModel;
    std::unordered_map<int, TcpConnectionPtr> _connMaps;
    std::mutex _connMutex;
};

#endif 
