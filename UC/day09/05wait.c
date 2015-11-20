/*File Name: 05wait.c
**Author: 
**Version: 使用wait函数获取子进程的推出状态
**Created Time: 15/08/10-15:28  */
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){

	pid_t pid = fork();
	switch(pid){
		case -1:perror("fork");
				exit(-1);
		case 0:printf("child starts to work%d\n",getpid());
			   sleep(10);
			   printf("child ends\n");
			   exit(100);
	}
	printf("parent starts to wait\n");
	int status;
	pid_t res = wait(&status);
	if(-1 == res){
		perror("wait"),exit(-1);
	}
	if(WIFEXITED(status)){
		printf("child %dends normally,exit NO.%d\n",res,WEXITSTATUS(status));
	}




	return 0;
}



