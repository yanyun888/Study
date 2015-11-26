/*File Name: 50time.c
**Author: 
**Version: 
**Created Time: 15/08/18-16:17  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>


int main(){

	time_t now = time(0);
	char* str = ctime(&now);
	printf("%s\n",str);

	return 0;
}
