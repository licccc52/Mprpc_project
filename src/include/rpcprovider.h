#pragma once
#include "google/protobuf/service.h"
//框架提供的专门发布rpc服务的网络对象类
//转用于发布的rpc网络框架服务类
//负责数据的序列化反序列化, IO收发

class RpcProvider{
public:
    //这里是框架提供给外部使用的, 可以发布rpc方法的函数接口
    void NotifyService(google::protobuf::Service *service);

    //启动rpc服务节点, 开始提供rpc远程网络调用服务
    void Run();

};