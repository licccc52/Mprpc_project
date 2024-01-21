#include "test.pb.h"
#include <iostream>
#include <string>

using namespace std;
using namespace Joy;

int main()
{
    LoginResponse resp1;
    ResultCode* result1 = resp1.mutable_result();
    result1->set_errcode(1);
    result1->set_errmsg("登录处理出错了");

    GetFriendListResponse resp2;
    ResultCode* result2 = resp2.mutable_result();
    result2->set_errcode(0);

    User* user1 = resp2.add_friendlist();
    user1->set_name("zhang san");
    user1->set_age(20);
    user1->set_sex(User::MAN);

    User* user2 = resp2.add_friendlist();
    user2->set_name("li si");
    user2->set_age(25);
    user2->set_sex(User::MAN);

    cout << resp2.friendlist_size() << endl;

    for(int i = 0; i < resp2.friendlist_size(); ++i)
    {
        User user = resp2.friendlist(i);
        cout << "name: " << user.name();
        cout << " age : " << user.age();
        cout << " sex: " << user.sex() << endl;
    }

    return 0;
}

// Test1
/*
int main()
{
    LoginRequest req1;
    req1.set_name("zhang san");
    req1.set_pwd("123456");

    // 序列化
    string send_str;
    if(req1.SerializeToString(&send_str))
    {
        cout << send_str << endl;
    }

    // 反序列化
    LoginRequest req2;
    if(req2.ParseFromString(send_str))
    {
        cout << req2.name() << endl;
        cout << req2.pwd() << endl;
    }

    return 0;
}
*/
