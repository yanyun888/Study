/* File Name: 05pp.c
** Author: 
** Version: 
** Created Time: 15/09/06-14:14  */
 
 
#include <stdio.h>
#include <stdlib.h>

int main(){

	int a=2;
	printf("%d\n",a++ + ++a);
	int b=1;
	printf("%d\n",++b + ++b);
	int c=3;
	printf("%d\n",c++ + c++);

	return 0;
}
