/*File Name: 01tcpa.c
**Author: 
**Version: 
**Created Time: 15/08/18-09:25  */
 
//基于TCP协议的一对多模型的实现
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>

int sockfd;

void func(int signo){
	printf("正在关闭服务器，请稍候...\n");
	close(sockfd);
	printf("关闭服务器成功\n");
	exit(0);
}

int main(){
		
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sockfd){
		perror("socket");
		exit(-1);
	}
	printf("创建socket成功\n");
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);//端口号转换host to net
	addr.sin_addr.s_addr = inet_addr("172.30.17.160");
	int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res){
		perror("bind");
		exit(-1);
	}
	printf("绑定成功\n");
	res = listen(sockfd,100);
	if(-1 == res){
		perror("listen");
		exit(-1);
	}
	printf("监听成功\n");
	printf("关闭服务器请按ctrl+C\n");

	signal(SIGINT,func);


	while(1){
		struct sockaddr_in rcv_addr;
		socklen_t len = sizeof(rcv_addr);
		int fd = accept(sockfd,(struct sockaddr*)&rcv_addr,&len);
		if(-1 == fd){
			perror("accept");
			exit(-1);
		}
		char* ip = inet_ntoa(rcv_addr.sin_addr);
		printf("客户端%s链接成功...\n",ip);
		//创建子进程相应链接上来的客户端
		pid_t pid = fork();
		if(-1 == pid){
			perror("fork");
			exit(-1);
		}
		if(0 == pid){//子进程
			while(1){
				char buf[100] = {0};
				res = read(fd,buf,sizeof(buf));
				if(-1 == res){
					perror("read");
					exit(-1);
				}
				printf("客户端%s发来的信息是：%s，大小是%d\n",ip,buf,res);
				//判断是否下线
				if(!strcmp(buf,"bye")){
					printf("客户端%s已经下线\n",ip);
					break;
				}
				res = write(fd,"I received!",12);
				if(-1 == res){
					perror("write");
					exit(-1);
				}
			}
			//关闭通信的socket
			close(fd);
			exit(0);
		}
	}
	//不断的相应客户端的链接请求
	//针对每个客户端可以不断的通信
	return 0;
}
