/*File Name:03relation.c
**Author: 
**Version: 
**Created Time: 15/08/10-11:50  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int i1 = 1; 
int main(){
	int i2 = 1;
	char* pc = (char*)malloc(sizeof(char)*10);
	strcpy(pc,"hello");
	pid_t pid = fork();
	if(-1 == pid){
		return 0;
	}
	if(0 == pid){
		i1 = 2;
		i2 = 2;
		strcpy(pc ,"world");
		printf("child:i1 = %d,i2 = %d,pc = %s\n",i1,i2,pc);
		exit(0);
	}
	sleep(1);
	printf("parent:i1 = %d.i2 = %d,pc = %s\n",i1,i2,pc);
//	else if()

	return 0;
}

