#include"rpcprovider.h"
#include"mprpcapplication.h"
#include"rpcheader.pb.h"
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

    std::cout << "RpcProvider::NotifyService ,service_name: " << service_name <<std::endl;

    for(int i=0; i < methodCnt; ++i)
    {
        //获取了服务对象指定下标的服务方法的描述(抽象描述)
        const google::protobuf::MethodDescriptor* pmethodDesc = pserviceDesc->method(i);
        std::string method_name = pmethodDesc->name();
        service_info.m_methodMap.insert({method_name, pmethodDesc});

        std::cout << "RpcProvider::NotifyService, method_name: " << method_name <<std::endl;
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
    
    //绑定连接回调 和 消息读写回调方法, 用muduo库 很好地 分离了网络代码和业务代码
    
    //绑定回调函数 处理新用户地连接
    server.setConnectionCallback(std::bind(&RpcProvider::OnConnection, this, std::placeholders::_1));
    
    //绑定回调函数 处理已经连接用户的读写事件
    server.setMessageCallback(std::bind(&RpcProvider::OnMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));


    //设置muduo库的线程数量-> muduo会根据数量自动分发IO线程和工作线程, 如果线程数量是1,那么IO线程和工作线程在一个线程中
    server.setThreadNum(4);
    
    std::cout << "RpcProvider::Run(), RpcProvider start service at ip: " << ip << " port: " << port << std::endl;
    //启动网络服务
    server.start();
    m_eventLoop.loop(); //启动epoll_wait(), 以阻塞的方式等待远程连接
}


//新socket连接回调
//rpc请求是一个短链接的请求, 类似http,请求一次结束之后, 服务端返回rpc方法的响应之后会主动关闭连接
void RpcProvider::OnConnection(const muduo::net::TcpConnectionPtr &conn)
{
    if(!conn->connected())
    {
        //rpc client的连接断开了
        std::cout << "RpcProvider::OnConnection, New Connection Comming;  getTcpInfoString() : " << conn->getTcpInfoString() << std::endl;
        conn->shutdown();
    }
}
/*
在框架内部, RpcProvider和RpcConsumer协商好之间通信用的protobuf数据类型
携带过来的数据的形式 : service_name method_name args =>> 定义proto的message类型, 进行数据头的序列化和反序列化

header_size(4个字节) + headser_str + args_str
4个字节中包含了除了参数以外的所有信息 : service_name method_name
*/

//已建立连接用户的读写时间回调, 如果远程有一个rpc服务的调用请求, 那么OnMessage方法就会相应
void RpcProvider::OnMessage(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer,  muduo::Timestamp)
{
    //网络上接收的远程rpc调用请求的字符流  Login args
    std::string recv_buf = buffer->retrieveAllAsString(); //缓冲区中提取所有的数据，并以字符串形式返回

    //从字节流中读取前四个字节的内容
    uint32_t header_size = 0;
    recv_buf.copy((char*)&header_size, 4, 0);

    //根据header_size读取数据头的原始字符流
    //这其中包含了service_name, method_name, args
    std::string rpc_header_str = recv_buf.substr(4, header_size);
    //之后再反序列化数据, 得到rpc请求的详细信息
    mprpc::RpcHeader rpcHeader;
    std::string service_name;
    std::string method_name;
    uint32_t args_size;
    if(rpcHeader.ParseFromString(rpc_header_str)) //将字符串 rpc_header_str 中的内容解析为 rpcHeader 对象
    {
        //数据头反序列化成功
        service_name = rpcHeader.service_name();
        method_name = rpcHeader.method_name();
        args_size = rpcHeader.args_size();   
    }
    else
    {
        //数据头反序列化失败
        std::cout << "header_size" << header_size  << std::endl;
        std::cout << "RpcProvider::OnmMessage : rpc_header_str: " << rpc_header_str << " parse error!" << std::endl;
        return;
    }

    //获取rpc方法参数的字符流数据
    std::string args_str = recv_buf.substr(4 + header_size, args_size);

    //打印调试信息
    std::cout << "=====================================" << std::endl;
    std::cout << " header_size :" << header_size << std::endl;
    std::cout << " rpc_header_str :" << rpc_header_str << std::endl;
    std::cout << " service_name :" << service_name << std::endl;
    std::cout << " method_name :" << method_name << std::endl;
    std::cout << " args_size :" << args_size << std::endl;
    std::cout << "=====================================" << std::endl;

    //获取service对象和method对象
    auto it = m_serviceMap.find(service_name);
    if(it == m_serviceMap.end())
    {
        std::cout << service_name << " is not exist!" << std::endl;
        return;
    }

    auto mit = it->second.m_methodMap.find(method_name);
    if(mit == it->second.m_methodMap.end())
    {
        std::cout << service_name << ": " << method_name << " is not exist!" << std::endl;
        return;
    }

    google::protobuf::Service *service = it->second.m_service;   //获取service对象
    const google::protobuf::MethodDescriptor *method = mit->second; //获取method对象

    //生成rpc方法调用的请求request和响应的response参数
    google::protobuf::Message *request = service->GetRequestPrototype(method).New();//产生一个具体的服务对象中某个服务方法的请求类型, 产生一个LoginRequest对象, 返回产生的Request的地址(LoginRequest)
    if(!request->ParseFromString(args_str))
    { 
        std::cout << "request parse error! content: " << args_str <<std::endl;
        return;
    }
    google::protobuf::Message *response = service->GetResponsePrototype(method).New();
    //在框架上根据远端rpc请求, 调用当前rpc节点上发布的方法

    //给下面的method方法的调用, 绑定一个Closure的回调函数
    google::protobuf::Closure *done =
        google::protobuf::NewCallback<RpcProvider, const muduo::net::TcpConnectionPtr&, google::protobuf::Message*>(this, &RpcProvider::SendRpcResponse, conn, response);

    //在框架上根据远端rpc请求, 调用当前rpc节点上发布的方法
    //new UserService().Login(controller, request, response, done)
    service->CallMethod(method, nullptr, request, response, done);

}

//Closure的回调操作, 用于序列化rpc响应和网络发送
void RpcProvider::SendRpcResponse(const muduo::net::TcpConnectionPtr& conn, google::protobuf::Message*response)
{
    std::string response_str;
    if(response->SerializeToString(&response_str)) //response进行序列化
    {
        //序列化成功后, 通过网络把rpc方法执行的结果发送回rpc的调用方
        conn->send(response_str);
    }
    else
    {
        std::cout << "SerializeToString response_str error! " << std::endl;
    }
    
}


