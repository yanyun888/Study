/*File Name: 05pthread.c
**Author: 
**Version: 
**Created Time: 15/08/18-17:18  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

void* task(void* p);

int main(){

	int num = 20;
	pthread_t tid;
	int res = pthread_create(&tid,NULL,task,(void*)&num);
	
	sleep(1);

	printf("num = %d\n",num);
	return 0;
}

void* task(void* p){
	*(int*)p = 100;


	return NULL;
}
