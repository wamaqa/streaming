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
    int SetBindPort(short port); //���ö˿�
    void SetIpPort(char *ip, short port);//����ip�˿�
    int InitSocket(int a, int b);        //socket��ʼ��
    void Accept();           //����socket
    char *  Send(char *data);    //��������


    int Send(const char * buf, int len, int flags);
    int Recv(char * buf, int len, int flags);
    char *GetAccept();       //��ȡ��������
    void disconnect();       //�Ͽ�����

	SocketData &Send(SocketData* data);    //��������

	SocketData &GetAcceptData();       //��ȡ��������
private:
    WORD wVersionRequested;
    WSADATA wsaData;
    SOCKADDR_IN addrSrv;
    int err;
    SOCKET sockSrv;
    SOCKET sockConn;
    SOCKET sockClient;
    int m_type; //0��ʾ�����, 1;��ʾ�ͻ���
    char m_host[64];
};

