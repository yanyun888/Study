/*File Name: 02sig.c
**Author: 
**Version: 
**Created Time: 15/08/12-09:53  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>

void fa(int signo){
	printf("get signo = %d\n",signo);
}



int main(){
	
//	printf("%d\n",sizeof(unsigned long int));

	sigset_t set,old;
	sigemptyset(&set);
	printf("set = %d\n",set.__val[0]);
/*
	sigaddset(&set,2);
	printf("set = %d\n",set);

	sigaddset(&set,3);
	printf("set = %d\n",set);

	sigaddset(&set,7);
	printf("set = %d\n",set);
	
	printf("struct set = %ld\n",set.__val[0]);
//	printf("set = %ld\n",set.__val[1]);

	if(sigismember(&set,2)){
		printf("sig2 exists\n");
	}


	puts("--------------------");
*/
	signal(2,fa);
	signal(3,fa);
	signal(50,fa);

	printf("pid = %d\n",getpid());
	
	int res = sleep(20);

	if(0 == res){
		printf("无信号屏蔽\n");
	}
	else{
		printf("睡了%d\n", 20-res);
	}


	printf("----------------\n");
	printf("开始屏蔽信号\n");

	sigaddset(&set,2);
	sigaddset(&set,3);
	sigaddset(&set,50);
	printf("set0 = %ld\n",set.__val[0]);
	printf("set1 = %ld\n",set.__val[1]);
	res = sigprocmask(SIG_SETMASK,&set,&old);
	if(-1 == res){
		printf("信号的屏蔽失败\n");
		return -1;
	}
	
	res = sleep(20);
	if(0 == res){
		printf("屏蔽的信号，没有被打断\n");
	}
	sigset_t pend;
	sigemptyset(&pend);
	res = sigpending(&pend);
	if(-1 == res){
		printf("获取来过的信号失败\n");
		return -1;
	}
	if(sigismember(&pend,2)){
		printf("2来过\n");
	}
	if(sigismember(&pend,3)){
		printf("3来过\n");
	}
	if(sigismember(&pend,50)){
		printf("50来过\n");
	}
	

	res = sigprocmask(SIG_SETMASK,&old,NULL);
	if(res == -1){
		printf("回复信号屏蔽失败\n");
		return -1;
	}

	while(1);

	return 0;
}
