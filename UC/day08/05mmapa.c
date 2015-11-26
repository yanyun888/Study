/*File Name:05mmapa.c
**Author: 
**Version: 
**Created Time: 15/08/07-14:03  */
 
 //文件到虚拟映射
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<sys/mman.h>

typedef struct emp{
	int id;
	char name[20];
	double salay;
}emp;

int main(){
	int fd = open("emp.dat",O_RDWR|O_CREAT|O_TRUNC,0644);
	if(-1 == fd){
		perror("open");
	}
	printf("create file succeed\n");
	int res = ftruncate(fd,sizeof(emp)*3);
	if(-1 == res){
		perror("fturncate");
	}
	printf("truncate succeed\n");
	void* pv = mmap(NULL,3*sizeof(emp),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(MAP_FAILED == pv){
		perror("mmap");
	}
	printf("map virtual file succeed\n");
	//文件和内存的映射的真正目的是什么？
	//A;能够使用指针直接对文件进行读写，更加灵活
	emp* pe = pv;

	pe[0].id = 1001;
	strcpy(pe[0].name,"zhangfei");
	pe[0].salay = 5966.9;

	pe[1].id = 1002;
	strcpy(pe[1].name,"guanyu");
	pe[1].salay = 8966.9;

	pe[2].id = 1003;
	strcpy(pe[2].name,"liubei");
	pe[2].salay = 9966.9;
		
	res = munmap(pv,sizeof(emp)*3);
	if(-1 == res){
		perror("munmap");
	}
	printf("unmap succeed\n");

	res = close(fd);
	if(-1 == res){
		perror("close");
	}
	printf("close succeed\n");
	return 0;
}

