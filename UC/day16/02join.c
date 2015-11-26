/*File Name: 02join.c
**Author: 
**Version: 
**Created Time: 15/08/19-10:03  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* task(void* p);
int main(){
		
	pthread_t tid;
	pthread_create(&tid,NULL,task,NULL);
	char* ps = NULL;
	
	pthread_join(tid,(void**)&ps);
	printf("retval = %s\n", ps);
	return 0;
}

void* task(void* pv){
	

//	char buf[20] = "hello";
	char* pc = "hello";
	return pc;
}
