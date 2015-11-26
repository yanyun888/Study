/*File Name: 05sigaction.c
**Author: 
**Version: 
**Created Time: 15/08/12-14:29  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>


void fa(int signo,siginfo_t* info ,void* p){

	printf("get signo = %d, from pid = %d\n",signo,info->si_pid);

}

int main(){

	struct sigaction action;
	action.sa_sigaction = fa;
	//sa_mask也可以设置
	action.sa_flags = SA_SIGINFO;
	
	sigaction(SIGINT,&action,NULL);
	
	printf("process %d starts to run\n",getpid());

	while(1);

	return 0;
}
