/*File Name: 05cancel.c
**Author: 
**Version: 
**Created Time: 15/08/19-14:14  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


void* task(void* pv);
void* task2(void* pv);

int main(){

	pthread_t tid;
	pthread_create(&tid,NULL,task,NULL);

	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);

	pthread_t tid2;
	pthread_create(&tid2,NULL,task2,&tid);

	pthread_join(tid,NULL);
	pthread_join(tid2,NULL);
	return 0;
}

void* task2(void* pv){
	printf("开始取消线程...\n");
	sleep(3);
//	int* tid = pv;
	pthread_cancel(*(pthread_t*)pv);
	printf("线程取消进程结束\n");
}

void* task(void* pv){
//	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
	while(1){
		printf("I am superman\n");
		sleep(1);
	}
	return NULL;

}
