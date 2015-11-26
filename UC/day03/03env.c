//环境表相关操作函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char* pc = getenv("SHELL");
	if(NULL == pc)
	{
		perror("getenv"),exit(-1);
	}
	printf("SHELL = %s\n",pc);// /bin/bash

	printf("---------------------\n");
	// 表示增加环境变量Mark到环境表中
	int res = setenv("Mark","abcd",1);
	if(-1 == res)
	{
		perror("setenv"),exit(-1);
	}
	// abcd
	printf("Mark = %s\n",getenv("Mark"));


	// 不允许被修改
	res = setenv("SHELL","abcd",0);
	if(-1 == res)
	{
		perror("setenv"),exit(-1);
	}
	// /bin/bash
	printf("SHELL = %s\n",getenv("SHELL"));

	// 实现修改环境变量的值
	res = setenv("SHELL","abcd",1);
	if(-1 == res)
	{
		perror("setenv"),exit(-1);
	}
	// abcd
	printf("SHELL = %s\n",getenv("SHELL"));
	
	printf("--------------------------\n");
	//删除指定的环境变量
	res = unsetenv("Mark");
	if(-1 == res)
	{
		perror("unsetenv"),exit(-1);
	}
	printf("Mark = %s\n",getenv("Mark"));
	
	printf("-------------------------\n");
	//增加环境变量
	res = putenv("Mark=abcd");
	if(0 != res)
	{
		perror("putenv"),exit(-1);
	}
	// abcd
	printf("Mark = %s\n",getenv("Mark"));
	
	//修改环境变量
	res = putenv("SHELL=/bin/bash");
	if(0 != res)
	{
		perror("putenv"),exit(-1);
	}
	// /bin/bash
	printf("SHELL = %s\n",getenv("SHELL"));
	
	printf("------------------------\n");
	// 清空环境表
	res = clearenv();
	if(0 != res)
	{
		perror("clearenv"),exit(-1);
	}
	// NULL
	printf("PATH =dd %s\n",getenv("PATH"));
	
	extern char** environ;
	//段错误
	printf("*environ = %s\n",*environ);
	return 0;
}






