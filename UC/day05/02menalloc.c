
#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){

	
	void* pi = sbrk(0);
	int* p1 = sbrk(sizeof(int));
	float* p2 = sbrk(sizeof(double));
	char* p3 = sbrk(sizeof(char)*6);
	
	*p1 = 118;
	*p2 = 3.14f;
	strcpy(p3,"hello");

	printf("%d,%lf,%s\n",*p1,*p2,p3);
	printf("%p,%p,%p,%p\n",pi,p1,p2,p3);
	printf("%p\n",pi);
	brk(pi);
	return 0;
}


