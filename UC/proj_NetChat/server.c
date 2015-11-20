/*File Name: server.c
**Author: 
**Version: 
**Created Time: 15/08/20-20:32  */
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<signal.h>
#include<string.h>
#include"server.h"


usr usrList[MAXUSR];
int sockfd;
short port = 8888;
//char* ip = "172.0.0.1";
char* ip = "192.168.43.46";
int pos = 0;

int main(){
	
	atexit(shut);
	init();//负责服务器的初始化
	signal(SIGINT,sigExit);
	usrConnect();
	return 0;
}
//客户端向服务器发送的第一条消息为客户的名字
void usrConnect(){
	while(1){
		struct sockaddr_in rcv_addr;
		socklen_t len = sizeof(rcv_addr);
		usrList[pos].fd = accept(sockfd,(struct sockaddr*)&rcv_addr,&len);
		judge3(usrList[pos].fd,accept);


		strcpy(usrList[pos].ip,inet_ntoa(rcv_addr.sin_addr));
		usrList[pos].state = USR_ONLINE;
		printf("客户端%s登陆成功\n",usrList[pos].ip);
		
		pthread_t tid;
		pthread_create(&tid,NULL,serviceThread,(void*)pos);
	}

}
void* serviceThread(void* ps){
	pos++;
	int posi = (int)ps;
	recv(usrList[posi].fd, usrList[posi].name, sizeof(usrList[posi].name),0);
	char logOnMsg[100]={0};
	sprintf(logOnMsg,"%s上线了",usrList[posi].name);
	puts(logOnMsg);
	servSend(logOnMsg,strlen(logOnMsg),posi);//负责向每一个用户发送上线信息

	while(1){
		char buf[100]={0};
		int res = recv(usrList[posi].fd,buf,sizeof(buf),0);
	//	judge2(res,recv);//仅仅打印错误信息，不退出
		if(res<0){
			perror("recv");
			printf("%s下线了",usrList[posi].ip);
			break;
		}
		if(!strcmp(buf,"bye")){
			char logOutMsg[100]={0};
			sprintf(logOutMsg,"客户端%s(%s)下线",usrList[posi].ip,usrList[posi].name);
			servSend(logOutMsg,strlen(logOutMsg),posi);
			puts(logOutMsg);
		}
	//	printf("%s:%s\n",usrList[posi].ip,buf);
		char msg[100]={0};
		sprintf(msg,"%s:%s",usrList[posi].name,buf );
		puts(msg);
		servSend(msg,strlen(msg),posi);
	}

	return NULL;
}
//先把信息存储在一个临时的存储区内，若数据是有效的，再把数据存储到真正的数据区
void servSend(char* pc,size_t len,int pos){
	//负责向在线的其他用户发送
	int i=0;
	for(i=0;i<MAXUSR;i++){
		if(usrList[i].state == USR_OFFLINE)
			continue;
		send(usrList[i].fd,pc,len,0);
	}
}


void sigExit(){
	printf("\b\b检测到ctrl+c\n");
	exit(0);
}

void shut(){
	printf("正在关闭服务器,请稍候...\n");
	int res = close(sockfd);
	judge1(res,close);
	printf("服务器关闭成功\n");
}

void init(){
	//负责服务器的初始化
	printf("正在初始化服务器\n");
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	judge1(sockfd,socket);
	printf("创建socket成功\n");
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ip);
	int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	judge1(res,bind);
	res = listen(sockfd,MAXUSR);//最大监听数量
	judge1(res,listen);
	printf("绑定socket成功\n");
	printf("服务器初始化成功\n");
}

