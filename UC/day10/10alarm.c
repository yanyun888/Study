/*File Name: 10alarm.c
**Author: 
**Version: 
**Created Time: 15/08/11-16:57  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>

void fa(int signo){
//	alarm(2);
	printf("get signo = %d\n",signo);
}


int main(){

	signal(SIGALRM,fa);
	int res = alarm(10);
	printf("res = %d\n",res);
	sleep(2);
	res = alarm(5);
	printf("res = %d\n",res);
	res = alarm(0);
	printf("res = %d\n",res);
	while(1);

	return 0;
}
