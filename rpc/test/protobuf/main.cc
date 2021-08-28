#include "test.pb.h"
#include <iostream>
#include <string>
using namespace fixbug;
using namespace std;

void func() {
    LoginRequest req;
    req.set_name("zhang san");
    req.set_pwd("123456");
    string str;
    if (req.SerializeToString(&str)) {
        cout << str << endl;
    }

    //un serialer
    cout << "-----" <<"\n";
    LoginRequest reqB;
    if (reqB.ParseFromString(str)) {
        cout << req.name() << endl;
        cout << req.pwd() << endl;
    }
}

void func1() {
    LoginResponse res;
    ResultCode* p = res.mutable_result();
    p->set_errcode(1);
    p->set_errmsg("already login");
    res.set_success(false);

    GetFriendListsResponse friends;
    User* user1 = friends.add_friend_list();
    user1->set_name("zhang san");
    user1->set_age(23);
    user1->set_sex(User::MAN);

    User* user2 = friends.add_friend_list();
    user1->set_name("li si");
    user1->set_age(25);
    user1->set_sex(User::MAN);

    cout << "size is" << friends.friend_list_size() << endl;
}

int main(int argc, char const *argv[])
{
    func1();
    return 0;
}
