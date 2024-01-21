#pragma once

// mprpc框架的基础类 - 单例
class MprpcApplication
{
public:
    static void Init(int argc, char **argv);
    static MprpcApplication& GetInstance()
    {
        static MprpcApplication app;
        return app;
    }

private:
    MprpcApplication();
    MprpcApplication(const MprpcApplication&) = delete;
    MprpcApplication(MprpcApplication&) = delete;


};