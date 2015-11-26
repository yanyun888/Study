//基于Socket的一对一通信模型 - 本地通信
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

int main(void)
{
	//1.创建socket,使用socket函数
	int sockfd = socket(AF_UNIX/*本地通信*/,SOCK_DGRAM/*数据报*/,0);
	if(-1 == sockfd)
	{
		perror("socket"),exit(-1);
	}
	printf("创建socket成功\n");
	//2.准备通信地址，使用结构体类型
	struct sockaddr_un addr;
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path,"a.sock");
	//3.绑定socket和通信地址，使用bind函数
	int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res)
	{
		perror("bind"),exit(-1);
	}
	printf("绑定成功\n");
	//4.进行通信，使用read/write函数
	char buf[100] = {0};
	res = read(sockfd,buf,sizeof(buf));
	if(-1 == res)
	{
		perror("read"),exit(-1);
	}
	printf("客户端发来的数据大小是：%d,数据内容是：%s\n",res,buf);
	//5.关闭socket,使用close函数
	close(sockfd);
	//练习：vi 02sockB.c文件，编写客户端的代码，负责发送数据
	return 0;
}




