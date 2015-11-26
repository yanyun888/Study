
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(   ){

	extern char** environ;//字符串指针数组
	//声明环境变量表
	char** p = environ;
	char buff[100];
	FILE* fp = fopen("envrecord.log","w");
	while( *p != NULL){
		//printf("%s\n",*p++);
		if(0 == strncmp(*p,"SHELL",5)){
			sprintf(buff,"%s",*p+6);
		}
		fprintf( fp ,"%s\n",*p);
		++p;
	}
	printf("%s\n",buff);
	//printf("sizeof(environ)=%d\n",sizeof(environ));

	return 0;
}
