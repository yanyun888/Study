/*File Name: 05signal.c
**Author: 
**Version: 
**Created Time: 15/08/11-14:35  */
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void fa(int signo){
	printf("get signo = %d\n",signo);
}

int main(){

	//2--忽略
	if( SIG_ERR == signal(SIGINT,SIG_IGN)){
		printf("signal %d failed\n",SIGINT);
		return -1;
	}
	//3--自定义处理
	if( SIG_ERR == signal(SIGQUIT,fa)){
		printf("signal %d failed\n",SIGQUIT);
		return -1;
	}
	if( SIG_ERR == signal(SIGKILL,fa)){
		perror("signal 9");
		printf("signal %d failed\n",SIGKILL);
		//return -1;
	}

	printf("pid = %d\n",getpid());
	while(1);
	return 0;
}

