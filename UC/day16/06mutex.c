/*File Name: 06mutax.c
**Author: 
**Version: 
**Created Time: 15/08/19-14:42  */
//使用互斥量解决线程同步的问题
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
char* buf[5];
int pos;
//pthread_mutex_t mutex;
sem_t sem;
void* task(void* pv);
int main(){
	//pthread_mutex_init(&mutex,NULL);
	sem_init(&sem,0,1);
//	printf("%d\n",mutex);
	pthread_t tid;
	pthread_create(&tid,NULL,task,"zhangfei");
	pthread_t tid2;
	pthread_create(&tid2,NULL,task,"guanyu");
	pthread_join(tid,NULL);
	pthread_join(tid2,NULL);
	int i = 0;
	for(i=0;i<pos;i++)
		printf("%s ",buf[i]);
	printf("\n");
	sem_destroy(&sem);
//	pthread_mutex_destroy(&mutex);
	//printf("%d\n",mutex);
	return 0;
}
void* task(void* pv){
//	pthread_mutex_lock(&mutex);
	sem_wait(&sem);
	buf[pos] = pv;
	sleep(1);
	pos++;
	sem_post(&sem);
//	pthread_mutex_unlock(&mutex);
//	return NULL;
}
