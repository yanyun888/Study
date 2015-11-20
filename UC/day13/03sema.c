/*File Name: 03sema.c
**Author: 
**Version: 
**Created Time: 15/08/14-14:37  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<signal.h>

int semid;
void func(int signo);
int main(){

	signal(SIGINT,func);
	key_t key = ftok(".",100);
	if(-1 == key){
		perror("ftok");
		exit(-1);
	}
	printf("key = %#x\n",key);
	semid = semget(key,2,IPC_CREAT | 0644);
	if(-1 == semid){
		perror("semget");
		exit(-1);
	}
	printf("创建semid = %d\n",semid);

	int res = semctl(semid,0,SETVAL,5);//信号量的下标和信号量的初始值
	if(-1 == res){
		perror("semctl");
		exit(-1);
	}


	while(1);

	return 0;
}



void func(int signo){
		
	printf("\b\b正在删除信号集,请稍候...\n");
	printf("接受到信号 signo = %d\n",signo);
	int res = semctl(semid,0,IPC_RMID);
	if(-1 == res){
		perror("semctl");
		printf("删除信号集失败\n");
	}
	else{
		printf("删除信号集成功\n");
	}
	exit(0);
}
