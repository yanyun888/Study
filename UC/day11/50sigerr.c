/*File Name: 50sigerr.c
**Author: 
**Version: 
**Created Time: 15/08/12-09:14  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int main(){

	printf("%p\n",SIG_ERR);
	printf("WNOHANG = %d\n",WNOHANG);
	printf("WUNTRACED = %d\n",WUNTRACED);
	printf("WCONTINUED = %d\n",WCONTINUED);
	return 0;
}
