/*File Name: 01shmb.c
**Author: 
**Version: 
**Created Time: 15/08/14-11:35  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<signal.h>

int shmid;


int main(){
	
	key_t key = ftok(".",100);
	if(-1 == key){
		perror("ftok");
		exit(-1);
	}
	shmid = shmget(key,4,0);
	if(-1 == shmid){
		perror("shmget");
	}


	void* pv = shmat(shmid,NULL,0);
	if( (void*)-1 == pv ){
		perror("shmat");
		exit(-1);
	}
	printf("挂载共享内存成功\n");


	int* pi = pv;
	printf("读取共享内存成功*pi = %d\n",*pi);


	int res = shmdt(pv);
	if(-1 == res){
		perror("shmdt");
	}
	printf("脱载共享内存成功\n");

	return 0;
}
