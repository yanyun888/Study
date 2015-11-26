/*File Name: 01tcpb.c
**Author: 
**Version: 
**Created Time: 15/08/18-10:04  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){

	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sockfd){
		perror("socket");
		exit(-1);
	}
	printf("创建socket成功\n");
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("172.30.17.160");
	int res = connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res){
		perror("connect");
		exit(-1);
	}
	while(1){
		char buf[100]={0};
		printf("请输入要发送的内容:\n");
		scanf("%s",buf);
		res = write(sockfd,buf,strlen(buf));
		if(-1 == res){
			perror("write");
			exit(-1);
		}
		//客户端下线
		if(!strcmp(buf,"bye")){
			printf("客户端下线\n");
			break;
		}
		char msg[100]={0};
		res = read(sockfd,msg,sizeof(msg));
		if(-1 == res){
			perror("read");
			exit(-1);
		}
		printf("从服务器读取的信息是%s,数据的大小是%d\n",msg,res);
	}
	close(sockfd);
	return 0;
}
