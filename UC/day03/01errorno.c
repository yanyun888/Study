

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>


int main(){

	FILE* fp =  fopen("/etc/passwd","r+");
	if(!fp){
		printf("%m\n");
//		perror("111");
//		fprintf(stderr,"file open failed:%s\n",strerror(errno));
//		return -1;
	}
	printf("open succeed\n");


	puts("--------------------");
		
	FILE* fp1 = fopen("/etc/passwd","w"); 
	if(!fp1){
		fprintf(stderr,"fopen:%s\n",strerror(errno));
		printf("fopen: %m\n");
		perror("fopen");
		return -1;
	}

	fclose(fp);
	return 0;
}



