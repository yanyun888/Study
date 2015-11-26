/*File Name: 01shma.c
**Author: 
**Version: 
**Created Time: 15/08/14-11:18  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<signal.h>


int shmid;

void sigFunc(int signo);
void exitFunc(void);

int main(){

	atexit(exitFunc);
	signal(SIGINT,sigFunc);
	key_t key = ftok(".",100);
	if(-1 == key){
		perror("ftok");
		exit(-1);
	}
	printf("%#x\n",key);
	
	shmid = shmget(key,4,IPC_CREAT|IPC_EXCL|0644);
	if(-1 == shmid){
		perror("shmget");
	//	exit(-1);
	}

	void* pv = shmat(shmid,NULL,0);
	if((void*)-1 == pv){
		perror("shmat");
		printf("挂接共享内存失败\n");
	}
	printf("挂接共享内存成功\n");

	int* pi = pv;
	*pi = 66;

	int res = shmdt(pv);
	if(-1 == res){
		perror("shmdt");
	}
	printf("脱节共享内存成功\n");
	printf("按ctrl+c删除共享内存\n");
	while(1);

	return 0;
}

void sigFunc(int signo){
	printf("\n接收到signo = %d，正在退出...\n",signo);
	exit(0);
}

void exitFunc(void){
	int res = shmctl(shmid,IPC_RMID,0);
	if(-1 == res){
		perror("shmctl");
	}
	printf("删除共享内存成功\n");
}
