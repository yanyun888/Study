/*File Name:05mmapb.c
**Author: 
**Version: 
**Created Time: 15/08/07-14:49  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<string.h>
#include<fcntl.h>


typedef struct emp{
	int id;
	char name[20];
	double salary;
}emp;


int main(){
	

	int fd = open("emp.dat",O_RDONLY);
	if(-1 == fd){
		perror("open");
	}
	void* p = mmap(NULL,sizeof(emp)*3,PROT_READ,MAP_SHARED,fd,0);
	if(MAP_FAILED == p){
		perror("mmap");
	}
	emp* pe = p;
	int i =0;
	for(i = 0;i<3 ;i++){
		printf("%d,%s,%g\n",pe[i].id,pe[i].name,pe[i].salary);
	}
	

	int res = munmap(p,sizeof(emp)*3);
	if(-1 == res){
		perror("munmap");
	}

	res = close(fd);
	if(-1 == res){
		perror("close");
	}

	return 0;
}
