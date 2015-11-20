/*File Name: h1.c
**Author: 
**Version: 
**Created Time: 15/08/18-17:33  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define PI 3.14

void* task(void* p);
int main(){
		
	int* pi = (int*)malloc(sizeof(4));
	if(NULL == pi){
		perror("malloc");
		exit(-1);
	}
	printf("请输入半径：\n");
	scanf("%d",pi);

	pthread_t tid;
	pthread_create(&tid,NULL,task,pi);
	
	printf("正在计算，请稍候...\n");
	sleep(2);
	free(pi);
	return 0;
}

//子线程的返回值是干什么用的？
void* task(void* p){
	int *pi = p;
	printf("半径为%d，圆的面积为%lf，圆的周长为%lf\n",*pi,PI*(*pi)*(*pi), *pi*PI*2);
	
	return NULL;
}

