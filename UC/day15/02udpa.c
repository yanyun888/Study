/*File Name: 02udpa.c
**Author: 
**Version: 
**Created Time: 15/08/18-11:34  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int sockfd;

int main(){
	
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(-1 == sockfd){
		perror("socket");
		exit(-1);
	}
	printf("创建socket成功\n");

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("172.30.17.160");
	int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res){
		perror("bind");
		exit(-1);
	}
	char buf[100] = {0};
//	int res = read(sockfd,buf,sizeof(buf));
	struct sockaddr_in recv_addr;
	socklen_t len = sizeof(recv_addr);
	res =  recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&recv_addr,&len);
	if(-1 == res){
		perror("recvfrom");
		exit(-1);
	}
	char* ip = inet_ntoa(recv_addr.sin_addr);
	printf("客户端%s发来的是%s,数据大小是%d\n",ip,buf,res);
	res = sendto(sockfd,"I received!",12,0,(struct sockaddr*)&recv_addr,len );
	if(-1 == res){
		perror("sendto");
		exit(-1);
	}
	printf("向客户端发送数据的大小是%d\n",res);
	close(sockfd);
	printf("关闭socket成功\n");

	return 0;
}

