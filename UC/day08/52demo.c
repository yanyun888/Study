/*File Name:52demo.c
**Author: 
**Version: 
**Created Time: 15/08/07-15:38  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main(){

	printf("%s\n",strerror(EAGAIN));
	return 0;
}
