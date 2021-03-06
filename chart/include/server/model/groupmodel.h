#ifndef GROUPMODEL_H
#define GROUPMODEL_H
#include "group.h"

class GroupModel {
public:
    bool createGroup(Group& group);
    void addGroup(int userid, int groupid, string role);
    //
    vector<Group> queryGroups(int userid);
    //根据指定的groupid查询群组用户id列表，除userid自己，主要用户群聊业务给群组其它成员群发消息
    vector<int> queryGroupUsers(int userid, int groupid);
};
#endif /* GROUPMODEL_H */
