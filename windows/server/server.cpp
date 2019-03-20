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
	FILE *file = fopen("test.jpg", "wb");
	while (true)
	{
		auto data = m_socket->GetAcceptData();
		char msg[50];
		sprintf(msg, "成功%d\n", data.index);
		fwrite(data.buff, sizeof(char), data.size, file);
		printf(msg);
		SocketData send;
		send.size = sizeof(msg);
		memcpy(send.buff, msg, send.size);
		send.dataType = STR;
		m_socket->Send(&send);
		if (data.status == 3) break;
	}
	fclose(file);
	getchar();    
	return 0;
}