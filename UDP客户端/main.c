#include <winsock.h>
#include <stdio.h>
#include <Windows.h>
#pragma comment(lib,"ws2_32.lib")		//加载2版本32位的lib

//UDP客户端
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



	SOCKET 客户端套接字;	//创建一个SOCKET句柄
	SOCKADDR_IN info;		//定义结构体

	info.sin_family = AF_INET;							//Windows只使用这种地址格式
	info.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");	//需要inet_addr()转换为十进制IP
	info.sin_port = htons(60000);						//端口需要转换为小端字节序
	/*
		SOCK_DGRAM = udp
		SOCK_STREAM = tcp
	*/
	客户端套接字 = socket(AF_INET, SOCK_DGRAM, 0);	//创建UDP的socket


	
	while (1)
	{
		char str[1024] = { 0 };	//定义一个缓冲区 存储要发送的数据

		gets(str);	//回车结束输入
		sendto(客户端套接字, str, strlen(str), 0, &info, sizeof(info));	//发送

	}



	closesocket(客户端套接字);	//关闭
	WSACleanup();				//释放
	system("pause");			//等待
}