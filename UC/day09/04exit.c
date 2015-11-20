/*File Name: 04exit.c
**Author: 
**Version: 各种进程终止函数的使用
**Created Time: 15/08/10-14:57  */
 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>


void show(void){
	printf("final work process(show)\n");
}


int main(){


	atexit(show);//仅仅会注册这个函数，并不会调用这个函数。
	printf("main is inited\n");
		
	//终止进程,自动调用atexit所注册的进程 
//	_Exit(100);
	exit(100);

	printf("main is ending\n");

	return 0;
}








