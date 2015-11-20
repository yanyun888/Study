/*File Name:50demo.c
**Author: 
**Version: 
**Created Time: 15/08/07-13:32  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
	long openmax = sysconf(_SC_OPEN_MAX);
	
	printf("%ld\n",openmax);
	mode_t old = umask(0020);
	printf("%d",old);

	return 0;
}
