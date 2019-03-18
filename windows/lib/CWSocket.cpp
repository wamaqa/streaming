#include "CWSocket.h"


CWSocket::CWSocket()
{

}


CWSocket::~CWSocket()
{
}

int CWSocket::SetBindPort(short port)
{
    err = 0;
    sockSrv = socket(AF_INET, SOCK_STREAM, 0);
    addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    addrSrv.sin_family = AF_INET;
    addrSrv.sin_port = htons(port);
    err = bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
    err = listen(sockSrv, 5);
    m_type = 0;
    return err;
}

void CWSocket::SetIpPort(char * ip, short port)
{
    sockConn = socket(AF_INET, SOCK_STREAM, 0);
    addrSrv.sin_addr.S_un.S_addr = inet_addr(ip);
    addrSrv.sin_family = AF_INET;
    addrSrv.sin_port = htons(port);
    connect(sockConn, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
    m_type = 1;
}

int CWSocket::InitSocket(int a,int b)
{
    wVersionRequested = MAKEWORD(a, b);

    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        return -10;
    }

    if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1) {
        WSACleanup();
        return -1;
    }
    return 0;
}

void CWSocket::Accept()
{
    int len = sizeof(SOCKADDR);
    sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);
    memcpy(m_host, inet_ntoa(addrClient.sin_addr), 64);
}

char * CWSocket::Send(char * data)
{
    char *recvBuf = new char[4096];
    switch (m_type)
    {
    case 0: {
        send(sockConn, data, strlen(data) + 1, 0);
    }break;
    case 1: {
        send(sockConn, data, strlen(data) + 1, 0);
        recv(sockConn, recvBuf, 4096, 0);
    }
    default:
        break;
    }
    return recvBuf;
}

int CWSocket::Send( const char * buf, int len, int flags)
{
    return send(sockConn, buf, len, flags);
}

int CWSocket::Recv(char * buf, int len, int flags)
{
    return recv(sockConn, buf, len, flags);
}

char * CWSocket::GetAccept()
{
    char *recvBuf = new char[4096];
    recv(sockConn, recvBuf, 4096, 0);
    return recvBuf;
}

void CWSocket::disconnect()
{
    closesocket(sockConn);
    WSACleanup();
}

SocketData &CWSocket::Send(SocketData *data) {
    char *recvBuf = new char[4096];
    char *buff = new char;
    memcpy(buff, data, sizeof(data));

    switch (m_type)
    {
        case 0: {
            send(sockConn, buff, sizeof(data) + 1, 0);
        }break;
        case 1: {
            send(sockConn, buff, sizeof(data) + 1, 0);
            recv(sockConn, recvBuf, 4096, 0);
        }
        default:
            break;
    }
    return (SocketData &)recvBuf;
}

SocketData &CWSocket::GetAcceptData() {
	char recvBuf[4096];
    recv(sockConn, recvBuf, sizeof(SocketData), 0);
	SocketData  *sock = new SocketData;
	memcpy(sock, recv, sizeof(SocketData));
    return *sock;
}
