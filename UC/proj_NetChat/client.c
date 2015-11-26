/*File Name: client.c
**Author: 
**Version: 
**Created Time: 15/08/20-20:33  */
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<pthread.h>
#include<string.h>
#include<errno.h>
#include"client.h"

int sockfd;
short port = 8888;
char* ip = "192.168.43.46";

int main(){
	
	atexit(shut);
	init();
	sendName();
	pthread_t tid;
	//pthread_create(&tid,NULL,recvMsg,&sockfd);

	while(1){
		char buf[100];
		printf("请输入:");
		scanf("%s",buf);
		if(!strcmp(buf,"bye"))
			break;
		int res = send(sockfd,buf,strlen(buf),0);
		judge1(res,send);
		printf("成功向服务器发送数据%s(%d)\n",buf,res);
	}
	return 0;
}

void* recvMsg(void* pv){
	int fd = *(int*)pv;
	while(1){
		sleep(1);
		char buf[100];
		int res = recv(sockfd,buf,sizeof(buf),0);
		judge2(res,recv);
		printf("%s\n",buf);
	}
}

void sendName(){
	char buf[24];
	printf("请输入昵称：");
	scanf("%s",buf);
	send(sockfd,buf,strlen(buf),0);

}

void init(){
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	judge1(sockfd,socket);
	printf("socket创建成功\n");
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ip);
	int res = connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	judge1(res,connect);
	printf("连接成功\n");
}

void shut(){
	printf("客户端下线\n");
	close(sockfd);
}
