/*File Name: 01sigset.c
**Author: 
**Version: 
**Created Time: 15/08/12-09:31  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

//信号集的基本操作

int main(){

	sigset_t set;
	printf("set = %ld\n",set);
	printf("size = %d\n",sizeof(set));
	printf("size of long int  = %d\n",sizeof(unsigned long int));


	return 0;
}
