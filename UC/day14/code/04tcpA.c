//基于Tcp协议的通信模型
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void)
{
	//1.创建socket,使用socket函数
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sockfd)
	{
		perror("socket"),exit(-1);
	}
	printf("创建socket成功\n");
	//2.准备通信地址，使用结构体类型
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("172.30.17.45");
	//解决重启程序时地址被占用的问题
	int reuseaddr = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&reuseaddr,sizeof(reuseaddr));
	//3.绑定socket和通信地址，使用bind函数
	int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res)
	{
		perror("bind"),exit(-1);
	}
	printf("绑定成功\n");
	//4.监听，使用listen函数
	res = listen(sockfd,100);
	if(-1 == res)
	{
		perror("listen"),exit(-1);
	}
	printf("监听成功\n");
	//5.响应客户端的连接请求，用accept函数
	struct sockaddr_in rcv_addr;
	socklen_t len = sizeof(rcv_addr);
	int fd = accept(sockfd,(struct sockaddr*)&rcv_addr,&len);
	if(-1 == fd)
	{
		perror("accept"),exit(-1);
	}
	char* ip = inet_ntoa(rcv_addr.sin_addr);
	printf("客户端%s连接上来...\n",ip);
	//6.进行通信，使用read/write函数
	char buf[100] = {0};
	res = read(fd,buf,sizeof(buf));
	if(-1 == res)
	{
		perror("read"),exit(-1);
	}
	printf("客户端发来的数据内容是：%s,数据大小是：%d\n",buf,res);
	res = write(fd,"I received!",12);
	if(-1 == res)
	{
		perror("write"),exit(-1);
	}
	printf("发送给客户端的数据成功，数据大小是：%d\n",res);
	//7.关闭socket,使用close函数
	close(fd);
	close(sockfd);
	//练习：vi 04tcpB.c文件，编写客户端代码
	return 0;
}






