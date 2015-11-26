/*File Name: 04sigaction.c
**Author: 
**Version: 
**Created Time: 15/08/12-14:06  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void fa(int signo){
	printf("working on signals,please wait...\n");
	sleep(10);
	printf("get signo = %d,signal comlete\n",signo);
}

int main(){
	
	printf("%d\n",sizeof(long int));
	printf("%d\n",sizeof(unsigned long int));

	struct sigaction action;
	action.sa_handler = fa;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask,3);//在处理2信号期间屏蔽信号3
	action.sa_flags = SA_NODEFER|SA_RESETHAND;//在处理2信号期间不屏蔽信号2

	sigaction(SIGINT,&action,NULL);

	printf("process %d starts to run\n",getpid());

	while(1);
	return 0;
}
