

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


int main(){
//	extern char** environ;//字符串指针数组
	printf("%s\n",getenv("SHELL"));

//	int res = setenv("SAMSON","123456",0);
	printf("LD_LIBRARY_PATH = %s\n",getenv("LD_LIBRARY_PATH"));
	printf("LIBRARY_PATH = %s\n",getenv("LIBRARY_PATH"));
	setenv("LD_LIBRARY_PATH",".",0);
/*
	//声明环境变量表
	char** p = environ;
	while( *p != NULL){
		printf("%s\n",*p);
		++p;
	}

*/
	return 0;
}



