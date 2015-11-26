/*File Name: 52exec.c
**Author: 
**Version: 
**Created Time: 15/08/11-20:44  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	
	printf("pid = %d\n",getpid());
	system("./54foo.out");
//	execl("54foo.out","54foo.out",NULL);
	puts("main func ends\n");

	return 0;
}
