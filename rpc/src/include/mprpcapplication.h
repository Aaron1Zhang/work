#pragma once
#include "mprpcconfig.h"


class MprpcApplication {
public:
    static void Init(int argc, char** argv);  
    static MprpcApplication& getInstance();
    static MprpcConfig& getConfig();
private:
    static MprpcConfig m_config;
    MprpcApplication() {};
    MprpcApplication(const MprpcApplication& ) = delete;
    MprpcApplication(MprpcApplication&& ) = delete;
};
