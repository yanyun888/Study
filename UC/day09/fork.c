/*File Name:fork.c
**Author: 
**Version: 
**Created Time: 15/08/10-11:14  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){

	printf("main function starts to run\n");
	//fork函数创建子进程
	pid_t pid = fork();


	if(-1 == pid){
		perror("fork");
	}
	else if(0 == pid){
		printf("I am child,my pid = %d,my parent pid = %d\n",getpid(),getppid());
		sleep(3);
		printf("I am child,my pid = %d,my parent pid = %d\n",getpid(),getppid());
	}
	else{
		sleep(1);
		printf("I am parent,my pid = %d,my child pid = %d\n",getpid(),pid);
		//父进程返回的是子进程的进程号
	}
	//考虑使用switch减少判断的次数

	printf("main function ends,pid = %d\n",pid);
	return 0;
}

