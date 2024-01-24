#include"rpcprovider.h"
#include"mprpcapplication.h"
/*
service_name => service 描述 => 
                        service 描述 => service* 记录服务对象
                        method_name => method方法对象
*/  

// 这里是框架提供给外部使用的, 可以发布rpc方法的函数接口
void RpcProvider::NotifyService(google::protobuf::Service *service)
{

    ServiceInfo service_info;

    //获取服务对象的描述信息
    const google::protobuf::ServiceDescriptor *pserviceDesc = service->GetDescriptor();

    //获取服务的名字
    std::string service_name = pserviceDesc->name();

    //获取服务对象service的方法的数量
    int methodCnt = pserviceDesc->method_count();

    std::cout << "service_name" << service_name <<std::endl;

    for(int i=0; i < methodCnt; ++i)
    {
        //获取了服务对象指定下标的服务方法的描述(抽象描述)
        const google::protobuf::MethodDescriptor* pmethodDesc = pserviceDesc->method(i);
        std::string method_name = pmethodDesc->name();
        service_info.m_methodMap.insert({method_name, pmethodDesc});

        std::cout << "method_name" << method_name <<std::endl;
    }
    service_info.m_service = service;//服务对象, 之后可以用该服务对象调用相应的map中的服务方法
    m_serviceMap.insert({service_name, service_info});
}


//启动rpc服务节点, 开始提供rpc远程网络调用服务
void RpcProvider::Run()
{
    std::string ip = MprpcApplication::GetInstance().GetConfig().Load("rpcserverip");
    uint16_t port = atoi(MprpcApplication::GetInstance().GetConfig().Load("rpcserverport").c_str());
    muduo::net::InetAddress address(ip, port);

    //创建TcpServer对象
    muduo::net::TcpServer server(&m_eventLoop, address, "RpcProvider");
    
    //绑定连接回调 和 消息读写回调方法, 分离了网络代码和业务代码
    server.setConnectionCallback(std::bind(&RpcProvider::OnConnection, this, std::placeholders::_1));
    server.setMessageCallback(std::bind(&RpcProvider::OnmMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));


    //设置muduo库的线程数量-> muduo会根据数量自动分发IO线程和工作线程, 如果线程数量是1,那么IO线程和工作线程在一个线程中
    server.setThreadNum(4);
    
    std::cout << "RpcProvider start service at ip: " << ip << " port: " << port << std::endl;
    //启动网络服务
    server.start();
    m_eventLoop.loop(); //启动epoll_wait(), 以阻塞的方式等待远程连接
}


//新socket连接回调
void RpcProvider::OnConnection(const muduo::net::TcpConnectionPtr &conn)
{

}

//已建立连接用户的读写时间回调
void RpcProvider::OnmMessage(const muduo::net::TcpConnectionPtr&, muduo::net::Buffer*,  muduo::Timestamp)
{

}