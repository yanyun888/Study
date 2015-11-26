/*File Name: 02udpb.c
**Author: 
**Version: 
**Created Time: 15/08/18-11:43  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>


int main(){
	
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(-1 == sockfd){
		perror("socket");
		exit(-1);
	}
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("172.30.17.45");
/*	int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res){
		perror("bind");
		exit(-1);
	}
	*/
	char buf[100] = {0};
	strcpy(buf,"hello");
	int res = sendto(sockfd,buf,strlen(buf)+1,0,(struct sockaddr*)&addr,sizeof(addr));
	//在发送数据的同时指定通讯目标的地址
	if(-1 == res){
		perror("sendto");
		exit(-1);
	}
	printf("成功发送数据到服务器，数据的大小是%d\n",res);
	
	char msg[100] = {0};
	res = recv(sockfd,msg,sizeof(msg),0);
	if(-1 == res){
		perror("read");
		exit(-1);
	}
	printf("成功接受到服务器的数据%s，大小是%d\n",msg,res);
	close(sockfd);
	printf("关闭socket\n");
	return 0;
}
