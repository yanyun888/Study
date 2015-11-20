/*File Name: 08pipea.c
**Author: 
**Version: 
**Created Time: 15/08/12-16:40  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>


int main(){
		
	int fd = open("a.pipe",O_WRONLY);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	
	int i = 0;
	for(i = 0;i<100;i ++){
		sleep(1);
		write(fd,&i,sizeof(int));
	}
	
	int res = close(fd);
	if(-1 == res){
		perror("close");
		exit(-1);
	}



	return 0;
}
