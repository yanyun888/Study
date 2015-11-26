/*File Name: 09raise.c
**Author: 
**Version: 
**Created Time: 15/08/11-16:29  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

void fa(int signo){
	printf("get signo = %d\n",signo);
}

int main(){
	
	signal(SIGINT,fa);
	puts("start..\n");
	int res = sleep(10);
	
	if(res == 0){
		printf("complete");
	}
	else{
		printf("%d left",res);
	}
	raise(SIGINT);
	while(1);
	

	return 0;
}
