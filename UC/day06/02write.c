

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){

	int fd = open("a.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	printf("open succeed\n");
	int res = write(fd,"hello",6);
	if(-1 == res){
		perror("write");
		exit(-1);
	}

	printf("write succeed,size = %d\n",res);

	res = close(fd);
	if(-1 == res){
		perror("close");
		exit(-1);
	}
	printf("close succeed\n");

	return 0;
}

