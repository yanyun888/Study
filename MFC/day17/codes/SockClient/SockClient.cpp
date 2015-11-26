// SockClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WINSOCK2.H>
#pragma comment(lib,"ws2_32.lib")
void UDPClient()
{
   //1 创建socket
	SOCKET hSockClient=socket(AF_INET,SOCK_DGRAM,0);
	if (INVALID_SOCKET==hSockClient)
	{
		return;
	}
  //2 通信
	SOCKADDR_IN addrSvr={0};
    addrSvr.sin_family=AF_INET;
	addrSvr.sin_port=htons(5679);
	addrSvr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
  //2.1 首先发送数据
	char* szSend="Hello,UDP Client!";
	sendto(hSockClient,szSend,strlen(szSend),0,
		(SOCKADDR*)&addrSvr,sizeof(addrSvr));
	//2.2 然后接收数据
	char szRecv[256]={0};
	int nLen=sizeof(addrSvr);
	int nRecv=recvfrom(hSockClient,szRecv,256,0,
		(SOCKADDR*)&addrSvr,&nLen);
	char* IP=inet_ntoa(addrSvr.sin_addr);
	printf("%s:%s,Len=%d\n",IP,szRecv,nRecv);

   // 3 关闭
	closesocket(hSockClient);
}
int main(int argc, char* argv[])
{
	//1 初始化Socket库
	WSADATA wsa={0};
	WSAStartup(MAKEWORD(2,2),&wsa);
	//2 使用(TCP/UDP通信)...
  	UDPClient();
	//3 卸载
	WSACleanup();
	return 0;
}

