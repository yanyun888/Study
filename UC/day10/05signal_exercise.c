/*File Name: 05signal_exercise.c
**Author: 
**Version: 
**Created Time: 15/08/11-14:51  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void func(int x);
int main(){
	
	if(SIG_ERR == signal(SIGINT,func)){
		printf("signal, SIGINT\n");
	}
	if(SIG_ERR == signal(SIGQUIT,func)){
		printf("signal, SIGQUIT\n");
	}
	if(SIG_ERR == signal(SIGKILL,SIG_DFL)){
		printf("signal, SIGKILL\n");
	}
	pid_t pid;
	switch(pid =fork()){
		case -1:perror("fork");
				exit(0);
		case 0:printf("child pid = %d\n",getpid());
			   while(1);
			   exit(0);
	}
	exit(0);

	return 0;
}

void func(int signo){

	printf("sig NO = %d\n",signo);
}
