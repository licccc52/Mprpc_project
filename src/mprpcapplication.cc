#include"mprpcapplication.h"
#include <iostream>
#include<unistd.h>
#include<string>

void ShowArgsHelp()
{
    std::cout << "format : command - i <configfile>" << std::endl;
}

void MprpcApplication::Init(int argc, char **argv)
{
    if(argc < 2)
    {
        ShowArgsHelp();
        exit(EXIT_FAILURE);
    }

    int c = 0;
    std::string config_file;
    while((c = getopt(argc, argv, "i:")) !=  -1)
    {
        switch(c)
        {
            case 'i':
                //有配置文件了
                config_file= optarg;
                break;
            case '?': // ? 用于处理未知的选项。
                std::cout << "invalid args!" << std::endl;
                ShowArgsHelp();
                exit(EXIT_FAILURE);
            case ':': // : 用于处理缺少参数的选项。
                std::cout << "need <config file>" << std::endl;
                ShowArgsHelp();
                exit(EXIT_FAILURE);
            default:
                break;
        }
    }

    //开始加载配置文件了 rpcserver_ip= rpcserver_port= zookeeper_ip= zookeeper_port=
}

MprpcApplication& MprpcApplication::GetInstance()
{
    static MprpcApplication app;
    return app;
}