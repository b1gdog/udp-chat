#include <winsock.h>
#include <stdio.h>
#include <Windows.h>
#pragma comment(lib,"ws2_32.lib")		//����2�汾32λ��lib

//UDP�ͻ���
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



	SOCKET �ͻ����׽���;	//����һ��SOCKET���
	SOCKADDR_IN info;		//����ṹ��

	info.sin_family = AF_INET;							//Windowsֻʹ�����ֵ�ַ��ʽ
	info.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");	//��Ҫinet_addr()ת��Ϊʮ����IP
	info.sin_port = htons(60000);						//�˿���Ҫת��ΪС���ֽ���
	/*
		SOCK_DGRAM = udp
		SOCK_STREAM = tcp
	*/
	�ͻ����׽��� = socket(AF_INET, SOCK_DGRAM, 0);	//����UDP��socket


	
	while (1)
	{
		char str[1024] = { 0 };	//����һ�������� �洢Ҫ���͵�����

		gets(str);	//�س���������
		sendto(�ͻ����׽���, str, strlen(str), 0, &info, sizeof(info));	//����

	}



	closesocket(�ͻ����׽���);	//�ر�
	WSACleanup();				//�ͷ�
	system("pause");			//�ȴ�
}