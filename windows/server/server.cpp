// server.cpp: 定义应用程序的入口点。
//
#include "server.h"
#include<stdio.h>
#include <CWSocket.h>

int main()
{
	CWSocket* m_socket = new CWSocket();
	m_socket->InitSocket(1, 1);
	m_socket->SetBindPort(6666);
	m_socket->Accept();
	printf((char *)m_socket->GetAcceptData().buff);

	SocketData send;
	send.size = sizeof("Test");
	memcpy(send.buff, "Test",send.size);
	send.dataType = STR;

	m_socket->Send(&send);
	getchar();    
	return 0;
}