#include"mprpcchannel.h"
#include<string>
#include"rpcheader.pb.h"
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<error.h>
#include"mprpcapplication.h"
/*
header_size + rpc_header_str(service_name method_name args_size) + args
*/
void MprpcChannel::CallMethod(const google::protobuf::MethodDescriptor* method,
                          google::protobuf::RpcController* controller, const google::protobuf::Message* request,
                          google::protobuf::Message* response, google::protobuf::Closure* done)
{
    const google::protobuf::ServiceDescriptor* sd = method->service(); //为了得到相应的service name
    std::string service_name = sd->name(); //service_name, 类名字
    std::string method_name = method->name(); //method_name

    //获取参数的序列化字符串长度 args_size
    std::string args_str;
    uint32_t args_size = 0;
    if(request->SerializeToString(&args_str)) //把request序列化, 结果储存在args_str中
    {
        args_size = args_str.size();
    }
    else
    {
        std::cout << "serialize request error!" << std::endl;
        return;
    }


    //定义rpc的请求header
    mprpc::RpcHeader rpcHeader;
    rpcHeader.set_service_name(service_name);
    rpcHeader.set_method_name(method_name);
    rpcHeader.set_args_size(args_size);

    uint32_t header_size = 0;
    std::string rpc_header_str;
    if(rpcHeader.SerializeToString(&rpc_header_str)) //把rpc_header序列化, 结果储存在rpc_header_str中
    {
        header_size = rpc_header_str.size(); 
        // mprpc::RpcHeader rpcHeader2;
        // if(!rpcHeader2.ParseFromString(rpc_header_str)){
        //     std::cout << " rpcHeader2.ParseFromString失败 " << std::endl;
        // };

    }
    else
    {
        std::cout << "serialize request error!" << std::endl;
        return;
    }

    //组织待发送的rpc请求的字符串
    std::string send_rpc_str;
    send_rpc_str.insert(0, std::string((char*)&header_size, 4)); // header_size, 4代表要插入的字节数
    send_rpc_str += rpc_header_str; //rpcheader, 序列化之后的string
    send_rpc_str += args_str; //args,   序列化之后的string

    //打印调试信息
    std::cout << "=====================================" << std::endl;
    std::cout << " header_size :" << header_size << std::endl;
    std::cout << " rpc_header_str :" << rpc_header_str << std::endl;
    std::cout << " service_name :" << service_name << std::endl;
    std::cout << " method_name :" << method_name << std::endl;
    std::cout << " args_str :" << args_str << std::endl;
    std::cout << "=====================================" << std::endl;

    //此处是客户端 使用tcp编程, 完成rpc方法的远程调用
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == clientfd)
    {
        std::cout << "create socket error! errno : " << errno << std::endl;
        exit(EXIT_FAILURE);
    }

    //读取配置文件信息
    std::string ip = MprpcApplication::GetInstance().GetConfig().Load("rpcserverip");
    uint16_t port = atoi(MprpcApplication::GetInstance().GetConfig().Load("rpcserverport").c_str());

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    //连接rpc服务节点
    if(-1 == connect(clientfd, (struct sockaddr*)&server_addr, sizeof(server_addr)))
    {
        std::cout << "connect error! errno : " << errno << std::endl;
        std::cout << "port: " << port << ";  ip: " << ip << std::endl;
        close(clientfd);
        exit(EXIT_FAILURE);
    }
    
    //发送rpc请求
    if(-1 == send(clientfd, send_rpc_str.c_str(), send_rpc_str.size(), 0))
    {
        std::cout << "send error! errno : " << errno << std::endl;
        close(clientfd);
        return;
    }

    //接收rpc请求的响应值
    char recv_buf[1024] = {0};
    int recv_size = 0;
    if(-1 == (recv_size = recv(clientfd, recv_buf, 1024, 0)))
    {
        std::cout << "recvive error! errno : " << errno << std::endl;
        close(clientfd);
        return;
    }

    //反序列化rpc调用的响应数据
    std::string response_str(recv_buf, 0, recv_size);
    if(!response->ParseFromArray(recv_buf, recv_size))
    {
        std::cout << "parse errpr! response_str : " << recv_buf << std::endl;
        close(clientfd);
        return;
    }

    close(clientfd);

}