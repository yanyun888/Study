/* File Name: 50voidptr.c
** Author: 
** Version: 
** Created Time: 15/09/14-10:57  */
 
 
#include <stdio.h>
#include <stdlib.h>


int main(){

	int* pi = (int*) malloc(4);
	void* pv = pi;
	printf("pv=%p\n",pv);

	
	free(pv);


	return 0;
}

