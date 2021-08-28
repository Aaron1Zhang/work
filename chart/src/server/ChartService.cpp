#include "ChartService.h"
#include "public.h"
#include <muduo/base/Logging.h>

ChartService* ChartService::instance() {
    static ChartService service;
    return &service;
}

MsgHandler ChartService::getMsgHandler(int msg_type) {
    if(handlers.find(msg_type) == handlers.end()) {
        return [=](const TcpConnectionPtr& conn, json& js, Timestamp) {
            LOG_ERROR << "msg: " << msg_type << "handle not find! ";
        };
    } else {
        return handlers[msg_type];
    }
}

void ChartService::login(const TcpConnectionPtr& conn, json& js, Timestamp time) {
    int id = js["id"].get<int>();
    string pwd = js["password"];

    User user = _userModel.query(id);
    json response;
    if (user.getId() == id && user.getPwd() == pwd) {
        LOG_INFO << "login !";
        if (user.getState() == "offline") {
            {
                lock_guard<std::mutex> lock(_connMutex);
                _connMaps.insert({id, conn});
            }

            user.setState("online");
            _userModel.updateState(user);

            response["msgid"] = LOGIN_MSG_ACK;
            response["errno"] = 0;
            response["id"] = id;
            response["name"] = user.getName();

            //query if there are offline message
            vector<string> off_msg = _offMsgModel.query(id);
            if (!off_msg.empty()) {
                response["offlinemsg"] = off_msg;
                _offMsgModel.remove(id);
            }
            //send back friend list
            vector<User> userVec = _friendModel.query(id);
            if (!userVec.empty()) {
                vector<string> vec2;
                for (User &user : userVec) {
                    json js;
                    js["id"] = user.getId();
                    js["name"] = user.getName();
                    js["state"] = user.getState();
                    vec2.push_back(js.dump());
                }
                response["friends"] = vec2;
            }
            // 查询用户的群组信息
            vector<Group> groupuserVec = _groupModel.queryGroups(id);
            if (!groupuserVec.empty())
            {
                // group:[{groupid:[xxx, xxx, xxx, xxx]}]
                vector<string> groupV;
                for (Group &group : groupuserVec)
                {
                    json grpjson;
                    grpjson["id"] = group.getId();
                    grpjson["groupname"] = group.getName();
                    grpjson["groupdesc"] = group.getDesc();
                    vector<string> userV;
                    for (GroupUser &user : group.getUsers())
                    {
                        json js;
                        js["id"] = user.getId();
                        js["name"] = user.getName();
                        js["state"] = user.getState();
                        js["role"] = user.getRole();
                        userV.push_back(js.dump());
                    }
                    grpjson["users"] = userV;
                    groupV.push_back(grpjson.dump());
                }

                response["groups"] = groupV;
            }
            
        } else {
            response["msgid"] = LOGIN_MSG_ACK;
            response["errno"] = 2;
            response["errmsg"] = "already login!";
        }
        
    } else {
        response["msgid"] = LOGIN_MSG_ACK;
        response["errno"] = 1;
        response["errmsg"] = "user id or password is wrong !";
    }
    conn->send(response.dump());
}

void ChartService::reg(const TcpConnectionPtr& conn, json& js, Timestamp time) {
    LOG_INFO << "reg";
    string name = js["name"];
    string pwd = js["password"];
    User user;
    user.setName(name);
    user.setPwd(pwd);
    json response;
    if (_userModel.insert(user)) {
        response["msgid"] = REG_MSG_ACK;
        response["error"] = 0;
        response["id"] = user.getId();
        conn->send(response.dump());
    } else {
        response["msgid"] = REG_MSG_ACK;
        response["error"] = 1;
        conn->send(response.dump());

    }
}

ChartService::ChartService() {
    handlers.insert({LOGIN_MSG, std::bind(&ChartService::login, this, _1, _2, _3)});
    handlers.insert({LOGINOUT_MSG, std::bind(&ChartService::loginout, this, _1, _2, _3)});
    handlers.insert({REG_MSG, std::bind(&ChartService::reg, this, _1, _2, _3)});   
    handlers.insert({ONE_CHAT_MSG, std::bind(&ChartService::onetone, this, _1,_2,_3)});
    handlers.insert({ADD_FRIEND_MSG, std::bind(&ChartService::addFriend, this, _1,_2,_3)});

// 群组业务管理相关事件处理回调注册
    handlers.insert({CREATE_GROUP_MSG, std::bind(&ChartService::createGroup, this, _1, _2, _3)});
    handlers.insert({ADD_GROUP_MSG, std::bind(&ChartService::addGroup, this, _1, _2, _3)});
    handlers.insert({GROUP_CHAT_MSG, std::bind(&ChartService::groupChat, this, _1, _2, _3)});
}

void ChartService::clientCloseException(const TcpConnectionPtr& conn) {
    User user;
    {
        lock_guard<mutex> lock(_connMutex);
        for(auto it = _connMaps.begin(); it != _connMaps.end(); ++it) {
            if (it->second == conn) {
                user.setId(it->first);
                _connMaps.erase(it);
                break;
            }
        }
    }
    
    if (user.getId() != -1) {
        user.setState("offline");
        if (_userModel.updateState(user)) {
            LOG_INFO << "delete user from conn_map";
        }
    }
   
}
// 处理注销业务
void ChartService::loginout(const TcpConnectionPtr &conn, json &js, Timestamp time) {
    int userid = js["id"].get<int>();
    {
        lock_guard<mutex> lock(_connMutex);
        auto it = _connMaps.find(userid);
        if (it != _connMaps.end()) {
            _connMaps.erase(it);
        }
    }

    // 用户注销，相当于就是下线，在redis中取消订阅通道
    //_redis.unsubscribe(userid); 

    // 更新用户的状态信息
    User user(userid, "", "", "offline");
    _userModel.updateState(user);
}
void ChartService::serverCloseException() {
    _userModel.resetState();
}

void ChartService::onetone(const TcpConnectionPtr& conn, json& js, Timestamp time) {
    int to = js["toid"].get<int>();
    {
        lock_guard<mutex> lock(_connMutex);
        auto iter = _connMaps.find(to);
        if (iter != _connMaps.end()) {
            auto to_connectPtr = iter->second;
            to_connectPtr->send(js.dump());
            return;
        }
    }
    _offMsgModel.insert(to, js.dump()); 
}   

void ChartService::addFriend(const TcpConnectionPtr& conn, json& js, Timestamp time) {
    int userid = js["id"].get<int>();
    int friendid = js["friendid"].get<int>();
    _friendModel.insert(userid, friendid);
}

// 创建群组业务
void ChartService::createGroup(const TcpConnectionPtr &conn, json &js, Timestamp time) {
    int userid = js["id"].get<int>();
    string name = js["groupname"];
    string desc = js["groupdesc"];
    // 存储新创建的群组信息
    Group group(-1, name, desc);
    if (_groupModel.createGroup(group)) {
        // 存储群组创建人信息
        _groupModel.addGroup(userid, group.getId(), "creator");
    }
}

// 加入群组业务
void ChartService::addGroup(const TcpConnectionPtr &conn, json &js, Timestamp time) {
    int userid = js["id"].get<int>();
    int groupid = js["groupid"].get<int>();
    _groupModel.addGroup(userid, groupid, "normal");
}

void ChartService::groupChat(const TcpConnectionPtr &conn, json &js, Timestamp time) {
    int uid = js["id"].get<int>();
    int groupid = js["groupid"].get<int>();

    vector<int> groupusers = _groupModel.queryGroupUsers(uid, groupid);
    lock_guard<mutex> lock(_connMutex);
    for (auto& uid: groupusers) {
        auto iter = _connMaps.find(uid);
        if (iter != _connMaps.end()) {

            iter->second->send(js.dump());
        } else {
            
            _offMsgModel.insert(uid, js.dump());
        }
    }
}