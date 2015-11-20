
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>



int main(){
	
	int fd = open("a.txt",O_RDWR|O_CREAT|O_EXCL,0644);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	puts("open file succeed");
	int res = close(fd);
	if(-1 == res){
		perror("close");
		exit(-1);
	}
	puts("close file succeed");
//	getch
	
	
//	printf();	
	return 0;
}

