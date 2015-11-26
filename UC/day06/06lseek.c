

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){

	int fd = open("b.txt",O_RDWR,0644);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}

	char c;
	read(fd,&c,1);
	printf("%c\n",c);
	lseek(fd,2,SEEK_CUR);

	int res = close(fd);
	if(-1 == res){
		perror("close");
		exit(-1);
	}

	return 0;
}

