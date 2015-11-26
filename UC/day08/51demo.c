/*File Name:51demo.c
 **Author: 
 **Version: 
 **Created Time: 15/08/07-13:55  */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buf[1024];
	scanf("%s", buf);
	printf("%s\n", buf);
	strcpy(buf, "标准输出已被I/O重定向为输出到文件o.txt。");
	printf("%s\n", buf);
	return 0;
}
