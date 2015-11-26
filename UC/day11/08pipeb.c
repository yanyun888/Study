/*File Name: 08pipeb.c
**Author: 
**Version: 
**Created Time: 15/08/12-16:46  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

	int fd = open("a.pipe",O_RDONLY);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	int num,res;
	do{
		res = read(fd,&num,sizeof(int));
		printf("get data = %d\n",num);
	}while(res);
	
	res = close(fd);
	if(-1 ==  res){

		perror("close");
		exit(-1);
	}

	return 0;
}
