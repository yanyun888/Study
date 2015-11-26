/*File Name: 03execl.c
**Author: 
**Version: 
**Created Time: 15/08/11-10:21  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	pid_t pid;
	switch(pid = vfork()){
		case -1:perror("vfork");
				exit(-1);
		case 0:printf("child %d starts\n",getpid());
				sleep(5);
			   system("ls");
			   	execl("./03test.out","b.out",NULL);
			   	printf("child ends\n");
			   	_exit(0);
			   //不要使用exit和return来返回
			   //_exit实现的是立即结束
	}
	printf("parent starts\n");
	printf("parent ends\n");
	
	return 0;
}
