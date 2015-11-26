//基于Socket的一对一通信模型 - 网络通信
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
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(-1 == sockfd)
	{
		perror("socket"),exit(-1);
	}
	printf("创建socket成功\n");
	//2.准备通信地址，使用结构体类型
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	// 由主机字节序转换为网络字节序
	addr.sin_port = htons(8888);
	// 将字符串形式的IP地址转换为整数类型
	addr.sin_addr.s_addr = inet_addr("172.30.17.45");
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
		perror("sockfd"),exit(-1);
	}
	printf("读取到客户端发来的数据内容是：%s,数据大小是：%d\n",buf,res);
	//5.关闭socket，使用close函数
	close(sockfd);
	//练习：vi 03socknetB.c文件，编写客户端的代码，并且发送数据内容
	return 0;
}




