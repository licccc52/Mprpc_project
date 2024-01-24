#include <iostream>
#include "mprpcapplication.h"
#include"user.pb.h"

int main(int argc, char**argv)
{
    //整个程序启动以后, 想使用mprpc框架享受rpc服务调用, 一定需要先调用框架的初始化函数(只初始化一次)
    MprpcApplication::Init(argc, argv); //读取conf文件


    //演示调用远程发布的rpc方法Login
    fixbug::UserServiceRpc_Stub;

    return 0;
}