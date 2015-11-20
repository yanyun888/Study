/*File Name: 07itimer.c
**Author: 
**Version: 
**Created Time: 15/08/12-15:28  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>
#include<signal.h>
#include<sys/types.h>


void fa(int signo){

	printf("one step forward%d\n",signo);
}

int main(){


	signal(SIGALRM,fa);

	struct itimerval timer;
	timer.it_interval.tv_sec = 2;
	timer.it_interval.tv_usec = 0;
	timer.it_value.tv_sec = 2;
	timer.it_value.tv_usec = 300000;

	setitimer(ITIMER_REAL,&timer,NULL);
	//getitimer获取定时器的信息

	while(1);
	return 0;
}
