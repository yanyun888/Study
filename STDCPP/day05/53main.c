/* File Name: 53main.c
** Author: 
** Version: 
** Created Time: 15/09/09-15:40  */
 
 
#include <stdio.h>
#include <stdlib.h>


int main(int argv,char* argc[],char* envirp[]){
	extern char** environ;//environ 是一个二级指针
	int i;
	for(i=0;i < argv;i++)
		printf("%s\n",argc[i]);

	return 0;
}

