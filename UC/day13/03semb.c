/*File Name: 03semb.c
**Author: 
**Version: 
**Created Time: 15/08/14-15:36  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/types.h>
#include<unistd.h>


int main(){

	key_t key = ftok(".",100);
	if(-1 == key){
		perror("ftok");
		exit(-1);
	}
	printf("key = %#x\n",key);
	int semid = semget(key,0,0);
	if(-1 == semid){
		perror("semget");
		exit(-1);
	}
	printf("semid = %d\n",semid);
	int i = 0;
	for(i = 0;i<10; i++){
		pid_t pid = fork();
		if(-1 == pid){
			perror("fork");
			exit(-1);
		}
		if(0 == pid){
			struct sembuf buf;
			buf.sem_num = 0;
			buf.sem_op = -1;
			buf.sem_flg = 0;//默认阻塞
			int res = semop(semid,&buf,1);//结构体的数量为1
			//模拟申请到资源的过程
			if(-1 == res){
				perror("semop");
				exit(-1);
			}
			printf("%d申请共享资源成功\n",getpid());
			sleep(10);
			printf("开始释放共享资源...\n");
			buf.sem_op = 1;
			res = semop(semid,&buf,1);
			if(-1 == res){
				perror("semop2");
				exit(-1);
			}
			printf("释放共享资源成功\n");
			exit(0);

		}
	}

	//semop

	return 0;
}
