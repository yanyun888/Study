
#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<unistd.h>

int main(){
	
	//
	int* pv = mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,0,0);
	if(MAP_FAILED == pv){
		perror("mmap");
		exit(-1);
	}
	printf("map succeed\n");
	*pv = 118;
	printf("%d,%p\n",*pv,pv);

	int res = munmap(pv,4);
	if(-1 == res){
		perror("munmao");
		exit(-1);
	}
	printf("unmap succeed\n");
	return 0;
}


