

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

void print(void){
	printf("1122\n");
	
}


int main(){
	

	int fd = open("a.txt",O_RDONLY);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	char buf[20];


	int res = read(fd,buf,sizeof(buf));
	if(-1 == res){
		perror("read");
		exit(-1);
	}

	res = close(fd);
	if(-1 == res){
		perror("read");
		exit(-1);
	}

	printf("buf = %s\n",buf);


	return 0;
}

