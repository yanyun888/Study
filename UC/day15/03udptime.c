/*File Name: 03udptime.c
**Author: 
**Version: 
**Created Time: 15/08/18-15:02  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<signal.h>
#include<string.h>
#include<time.h>

int sockfd;

void exitFunc(int signo){
	printf("正在关闭服务器，请稍候...\n");
	close(sockfd);
	printf("服务器关闭成功\n");
	exit(-1);
}

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
	
	printf("按Ctrl+C关闭服务器...");
	signal(SIGINT,exitFunc);
	while(1){
		char buf[50] = {0};
		struct sockaddr_in recv_addr;
		socklen_t len = sizeof(recv_addr);
		res = recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&recv_addr,&len);
		if(-1 == res){
			perror("recvfrom");
			exit(-1);
		}
		char* ip = inet_ntoa(recv_addr.sin_addr);
		printf("客户端%s发来的是%s数据大小是%d\n",ip,buf,res);
		time_t now = time(0);
		struct tm* p_tm = localtime(&now);
		char msg[50];
		sprintf(msg,"%04d-%02d-%02d,%02d:%02d:%02d",
				p_tm->tm_year+1900,p_tm->tm_mon+1,p_tm->tm_mday,
				p_tm->tm_hour,p_tm->tm_min,p_tm->tm_sec);
		res = sendto(sockfd,msg,strlen(msg),0,(struct sockaddr*)&recv_addr,len);
		if(-1 == res){
			perror("sendto");
			exit(-1);
		}
		printf("向客户端发送的数据大小是%d\n",res);

	}


	return 0;
}
