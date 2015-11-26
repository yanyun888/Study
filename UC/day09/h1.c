/*File Name: h1.c
**Author: 
**Version: 
**Created Time: 15/08/10-16:13  */

//exit(-1)在系统判定为正常退出，返回值为255


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){

	printf("parent starts\n");
	pid_t pid1=0,pid2=0;
	pid1 = fork();
	switch(pid1){
		case -1:perror("fork1");
				exit(-1);
		case 0:
			printf("child1 %d starts\n",getpid());
			sleep(5);
			printf("child1 ends\n");
			exit(100);
		default:
			pid2 = fork();
			switch(pid2){
				case -1:perror("fork2");
						exit(-1);
				case 0:	printf("child2 %d starts\n",getpid());
						sleep(10);
						printf("child2 ends\n");
						exit(-1);
			}
	}
	int status;
	printf("parents starts to wait\n");
	int res = waitpid(pid2,&status,0);
	printf("res = %d,status = %d,is normal = %d, exit NO.%d\n",
			res,status,WIFEXITED(status),WEXITSTATUS(status));
	printf("pid = %d,pid1 = %d,pid2 = %d\n",getpid(),pid1,pid2); 
	printf("parent ends\n");
	return 0;
}
