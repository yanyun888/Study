/*File Name: 53alarm.c
 **Author: 
 **Version: 
 **Created Time: 15/08/11-20:53  */
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
void sigalrm (int signum){
	time_t t = time (NULL);
	struct tm* lt = localtime (&t);
	printf ("\r%02d:%02d:%02d 按回车键退出", lt->tm_hour, lt->tm_min, lt->tm_sec);
	fflush(stdout);
	alarm (1);
}
int main(){
	if (signal (SIGALRM, sigalrm) == SIG_ERR){
		perror ("signal");
		return -1;
	}
	sigalrm (SIGALRM);
	getchar();
	return 0;
}
