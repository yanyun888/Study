/*File Name: 06sigqueue.c
**Author: 
**Version: 
**Created Time: 15/08/12-14:49  */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void fa(int signo,siginfo_t* info,void* p){
	printf("get signo = %d from %d,data = %d\n",signo,info->si_pid,info->si_value);
}

int main(){
	//sigqueue发送信号，sigaction处理信号	
	struct sigaction action;
	action.sa_sigaction = fa;
	action.sa_flags = SA_SIGINFO;

	sigaction(40,&action,NULL);

	pid_t pid = fork();
	if(-1 == pid){
		perror("fork");
		exit(0);
	}
	if(pid == 0){
		printf("child %d starts to run\n",getpid());
		union sigval value;
		int i = 0;
		for(i = 0;i<10;i++){
			value.sival_int=i;
			sigqueue(getppid(),40,value);
			//直接传入结构体的变量名即可
		}
		exit(0);
	}
	while(1);
	return 0;
}
