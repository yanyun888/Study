/*File Name: 50on_exit.c
**Author: 
**Version: 
**Created Time: 15/08/11-19:19  */
 
 
#include<stdio.h>
#include<stdlib.h>

void doexit(int status,void* arg){
	printf("%d,%s",status,(char*)arg);
}

int main(){

	on_exit(doexit,"calling exit func\n");
	printf("main exits\n");
	return 0;
}
