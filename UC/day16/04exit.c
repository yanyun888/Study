/*File Name: 04exit.c
**Author: 
**Version: 
**Created Time: 15/08/19-11:25  */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void* task(void* pv);
int main(){
	pthread_t tid;
	pthread_create(&tid,NULL,task,NULL);
	int pi;// = NULL;
	pthread_join(tid, (void**)&pi);
	printf("exit status = %d\n",pi);
	return 0;
}
void* task(void* pv){
	int i = 0;
	for(i=1;i<21;i++){
		if(10 == i)
			pthread_exit((void*)i);
		printf("%d\n",i);
	}
}
