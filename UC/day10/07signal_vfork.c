/*File Name: 07signal_vfork.c
**Author: 
**Version: 
**Created Time: 15/08/11-15:08  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void fa(int signo){

	printf("get signo = %d\n",signo);
}

int main(){
	
	signal(SIGINT,fa);
	signal(SIGQUIT,SIG_IGN);
	signal(SIGKILL,SIG_DFL);
	pid_t pid;
	switch(pid = vfork()){
		case -1:perror("fork");
				exit(-1);
		case 0:printf("child %d\n",getpid());
			   while(1);
			   //execl("./proc","proc",NULL);
	}
	printf("parent ends\n");
	
	return 0;
}
