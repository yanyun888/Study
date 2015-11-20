/*File Name: 03join.c
**Author: 
**Version: 
**Created Time: 15/08/19-10:16  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


void* task(void* ps);

int main(){
	
	pthread_t tid;
	int sum = 0;
	pthread_create(&tid,NULL,task,&sum);

	pthread_detach(tid);
	int* pi=NULL;
	pthread_join(tid,(void**)&pi);
	printf("num = %d\n",*pi);

	return 0;

}
//也可以使用静态局部变量，或全局变量
void* task(void* ps){
	*(int*)ps = 0;
	int i = 1;
	for(i=1;i<101;i++)
		*(int*)ps+=i;
	sleep(3);
	return ps;
}




