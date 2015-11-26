/*File Name: 08kill.c
**Author: 
**Version: 
**Created Time: 15/08/11-16:14  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

void fa(int signo){
	printf("get signo = %d\n",signo);
}
int main(){
	pid_t pid;
	switch(pid = fork()){
		case -1:perror("fork");
				exit(-1);
		case 0:printf("child %d starts\n",getpid() );
			   signal(50,fa);
			   while(1);
	}
	sleep(1);
	printf("parent starts\n");
	if(0 == kill(pid,0)){
		printf("child existed\n");
		if(-1 ==  kill(pid,50) ){
			printf("kill %d failed\n",pid);
	
		}
	}

	return 0;
}
