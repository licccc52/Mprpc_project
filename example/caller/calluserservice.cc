#include <iostream>
#include "mprpcapplication.h"
#include "user.pb.h"
#include "mprpcchannel.h"

int main(int argc, char**argv)
{
    //整个程序启动以后, 想使用mprpc框架享受rpc服务调用, 一定需要先调用框架的初始化函数(只初始化一次)
    MprpcApplication::Init(argc, argv); //读取conf文件


    //演示调用远程发布的rpc方法Login
    fixbug::UserServiceRpc_Stub stub(new MprpcChannel());

    //rpc方法的请求参数
    fixbug::LoginRequest request;
    request.set_name("zhang san");
    request.set_pwd("123456");

    //rpc方法的响应
    fixbug::LoginResponse response;

    //发起rpc方法的调用 同步rpc调用过程 MprpcChannel::callmethod
    stub.Login(nullptr, &request, &response, nullptr); //RpcChannel->RpcChannel : MprpcChannel::CallMethod 集中起来做所有rpc方法调用的参数序列化的网络发送

    //一次rpc调用完成, 读调用的结果
    if(response.result().errcode() == 0)
    {
        std::cout << "rpc login response: " << response.success() << std::endl;
    }
    else
    {
        std::cout << "rpc login response error : " << response.result().errmsg();
    }

    return 0;
}