// server.cpp: 定义应用程序的入口点。
//
#include "client.h"
#include<stdio.h>
#include <CWSocket.h>
#include<io.h>
#include <list>

int main()
{
	CWSocket* m_socket = new CWSocket();
	m_socket->InitSocket(1, 1);
	m_socket->SetIpPort("127.0.0.1", 6666);

	FILE* file = fopen(".\\res\\test.jpg", "rb");
	int size = filelength(fileno(file));
	char* buff =(char *)malloc(size);
	fread(buff, sizeof(char), size, file);
	fclose(file);

	std::list<SocketData> datas;
	int count = size / 3072 + 1;
	for (int i = 0; i < count; i++)
	{
		SocketData data;
		data.index = i;
		data.dataType = PNG;
		data.status = 0 == i ? 1 : 2;
		if (count == i + 1)
		{
			data.size = size - i * 3072;
			data.status = 3;
		}
		else
			data.size = 3072;
		memcpy(data.buff, &(buff[i * 3072]), data.size);
		datas.push_back(data);
	}

	for(SocketData data : datas)
	{
		printf("发送%d", data.index);
		auto sock = m_socket->Send(&data);
		printf(sock.buff);
	}
	getchar();    
	return 0;
}