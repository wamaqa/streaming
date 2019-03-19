// server.cpp: 定义应用程序的入口点。
//
#include "client.h"
#include<stdio.h>
#include <CWSocket.h>

int main()
{
	CWSocket* m_socket = new CWSocket();
	m_socket->InitSocket(1, 1);
	m_socket->SetIpPort("127.0.0.1", 6666);

	SocketData *send = new SocketData;
	memcpy(send->buff, "Test", sizeof("Test"));
	send->dataType = STR;
	send->size = sizeof("Test");
	auto sock = m_socket->Send(send);
	printf(sock.buff);
	//m_socket->SetBindPort(6666);
	//m_socket->Accept();
	//printf(m_socket->GetAccept());
	getchar();    return 0;
}