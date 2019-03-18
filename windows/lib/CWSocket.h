#pragma once
#include <Winsock2.h>
#include <stdio.h>
#include "SocketData.h"

#pragma comment(lib, "Ws2_32.lib")
class CWSocket
{
public:
        SOCKADDR_IN addrClient;
public:
    CWSocket();
    ~CWSocket();
    int SetBindPort(short port); //设置端口
    void SetIpPort(char *ip, short port);//设置ip端口
    int InitSocket(int a, int b);        //socket初始化
    void Accept();           //接收socket
    char *  Send(char *data);    //发送请求


    int Send(const char * buf, int len, int flags);
    int Recv(char * buf, int len, int flags);
    char *GetAccept();       //获取接收数据
    void disconnect();       //断开链接

	SocketData &Send(SocketData* data);    //发送请求

	SocketData &GetAcceptData();       //获取接收数据
private:
    WORD wVersionRequested;
    WSADATA wsaData;
    SOCKADDR_IN addrSrv;
    int err;
    SOCKET sockSrv;
    SOCKET sockConn;
    SOCKET sockClient;
    int m_type; //0表示服务端, 1;表示客户端
    char m_host[64];
};

