// SockSvr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WINSOCK2.H>
#pragma comment(lib,"ws2_32.lib")

void TCPServer()
{
	//1 ����
	SOCKET hSockSvr=
		socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (INVALID_SOCKET==hSockSvr)
	{
		return;
	}
	//2 ��
	SOCKADDR_IN addrSvr={0};
	addrSvr.sin_family=AF_INET;
	addrSvr.sin_port=htons(5678);
	addrSvr.sin_addr.S_un.S_addr=INADDR_ANY;
	bind(hSockSvr,(SOCKADDR*)&addrSvr,sizeof(addrSvr));
	//3 ����
	listen(hSockSvr,5);
	//4 ���տͻ�������
	printf("�ȴ��ͻ�������...\n");
	SOCKADDR_IN addrClient={0};
	int nLen=sizeof(addrClient);
	SOCKET hSockClient=
		accept(hSockSvr,(SOCKADDR*)&addrClient,&nLen);
    printf("�Ѿ���ͻ��˽������ӡ�\n");
	//5 ͨ��
	//5.1 ���������Ƚ�������
	char szRecv[256]={0};
	int nRecv=recv(hSockClient,szRecv,256,0);
	printf("Data:%s,Len:%d",szRecv,nRecv);
	// 6 �ر��׽���
	closesocket(hSockClient);
	closesocket(hSockSvr);
}

void UDPServer()
{
    //1 ����
	SOCKET hSockSvr=socket(AF_INET,SOCK_DGRAM,0);
	if (INVALID_SOCKET==hSockSvr)
	{
		return;
	}
	//2 ��
	SOCKADDR_IN addrSvr={0};
    addrSvr.sin_family=AF_INET;
	addrSvr.sin_port=htons(5679);
	addrSvr.sin_addr.S_un.S_addr=INADDR_ANY;
	bind(hSockSvr,(SOCKADDR*)&addrSvr,sizeof(addrSvr));
	//3 ͨ��
	//3.1���������Ƚ�������
	char szRecv[256]={0};
	SOCKADDR_IN addrClient={0};
	int nLen=sizeof(addrClient);
	int nRecv=recvfrom(hSockSvr,szRecv,256,0,
		(SOCKADDR*)&addrClient,&nLen);
	char* IP=inet_ntoa(addrClient.sin_addr);
	printf("%s:%s,Len=%d\n",IP,szRecv,nRecv);
	//3.2 Ȼ��������
	char* szSend="Hello,UDP Server��";
	sendto(hSockSvr,szSend,strlen(szSend),0,
		(SOCKADDR*)&addrClient,nLen);
	//4 �ر�
	closesocket(hSockSvr);




}

int main(int argc, char* argv[])
{
	//1 ��ʼ��Socket��
	WSADATA wsa={0};
	WSAStartup(MAKEWORD(2,2),&wsa);
	//2 ʹ��(TCP/UDPͨ��)...
    //TCPServer();
	UDPServer();
	//3 ж��
	WSACleanup();
	
	return 0;
}

