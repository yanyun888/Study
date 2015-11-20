

#include<stdio.h>
#include<stdlib.h>

int main(){
	

	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	int* p3 = (int*)malloc(sizeof(int));
	int* p4 = (int*)malloc(sizeof(int));
	int* p5 = (int*)malloc(sizeof(int));
	
	printf("%p,%p,%p,%p,%p\n",p1,p2,p3,p4,p5);
	return 0;
}

