


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
	
	int fd = open("emp.dat",O_RDONLY);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	emp* p_e1 = (emp*)malloc(sizeof(emp));
	int res = read(fd,p_e1,sizeof(emp));
	if(-1 == res){
		perror("read");
		exit(-1);
	}
	printf("%s,%d,%lf\n",p_e1->name,p_e1->id,p_e1->salary);
	
	res = read(fd,p_e1,sizeof(emp));
	if(-1 == res){
		perror("read");
		exit(-1);
	}
	printf("%s,%d,%lf\n",p_e1->name,p_e1->id,p_e1->salary);

	res = read(fd,p_e1,sizeof(emp));
	if(-1 == res){
		perror("read");
		exit(-1);
	}
	printf("%s,%d,%lf\n",p_e1->name,p_e1->id,p_e1->salary);

	res = close(fd);
	if(-1 == res){
		perror("close");
		exit(-1);
	}
	free(p_e1);
	p_e1 = NULL;
	return 0;
}


