/*File Name:01pid.c
**Author: 
**Version: 
**Created Time: 15/08/10-10:26  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>


int main(){
	printf("pid = %d\n",getpid());
	printf("ppid = %d\n",getppid());
	printf("gid = %d\n",getgid());
	printf("uid = %d\n",getuid());
	return 0;
}
