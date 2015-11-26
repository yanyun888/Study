

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(){
	

	void* p = (void*)sbrk(0);
	if((void*)-1 == p){
		perror("sbrk");
		exit(-1);
	}
	void* p1 = (void*)sbrk(4);
	void* p2 = (void*)sbrk(4);
	void* p3 = (void*)sbrk(4);
	
	getchar();
//	void* p1 =(void*)-1;

	printf("%p,%p,%p,%p\n",p,p1,p2,p3);
	printf("----------------\n");
	void* cur =(void*)sbrk(0);
	printf("%p\n",cur);
	printf("----------------\n");
	getchar();
	printf("释放了1个字节\n");
	sbrk(-1);

	getchar();
	printf("释放了2个字节\n");
	sbrk(-2);
	getchar();
	
	return 0;
}
