/*File Name: 04pthread.c
**Author: 
**Version: 
**Created Time: 15/08/18-16:47  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

void* task(void* );
int main(){
	
	pthread_t tid;
	int res = pthread_create(&tid,NULL,task,NULL);
	if( 0!=res ){
		printf("%s\n",strerror(res));
		exit(-1);
	}
	printf("创建新线程成功，进程结束\n");

	//while(1);
	sleep(1);
	printf("子线程的线程ID是:%lu\n",tid);
	printf("主线程的线程ID是:%lu\n",pthread_self());
	return 0;
}

void* task(void* arg){
//	while(1){
		printf("我就是创建出来的新线程\n");
//	}
	return NULL;
}
