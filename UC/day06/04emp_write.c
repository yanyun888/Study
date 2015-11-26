

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>


typedef struct emp{
	char name[16];
	unsigned id;
	double salary;
}emp;

//编号，姓名，薪水
//.dat表示二进制文件


int main(){
	
	int fd = open("emp.dat",O_CREAT|O_WRONLY|O_APPEND,0644);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	emp e1[3]={ {"Samson",568,7500},{"Zhang",555,8000},{"Li",554,9000} };
	int res,i;
	for(i=0;i<3;i++){
		res = write(fd,&e1[i],sizeof(emp));
		if(-1 == res){
			perror("write");
			exit(-1);
		}
	}
	res = close(fd);
	if(-1 == res){
		perror("close");
		exit(-1);
	}

	return 0;
}


