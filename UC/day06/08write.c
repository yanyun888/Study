
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<time.h>

int main(){
	int fd = open("num2.dat",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	unsigned long int i;
	time_t t1 = time(0);
	for(i=1;i<=1000000;i++){
		write(fd,&i,sizeof(unsigned long int));
	}
	close(fd);
	time_t t2 = time(0);
	printf("%lf\n",difftime(t2,t1));
	return 0;
}

