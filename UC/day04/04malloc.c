

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	
	printf("%d\n",getpid());
	int* p = (int*)malloc(sizeof(int));
	while(1);
	return 0;
}



