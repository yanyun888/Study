/*File Name:h1.c
**Author: 
**Version: 
**Created Time: 15/08/07-19:04  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){

	printf("%s\n",(char*)get_current_dir_name());
	char arr[50]="123456";
	char* pc = getcwd(arr,50);
	if(NULL == pc){
		perror("getcwd");
	}
	printf("%s\n",arr);
	printf("%d\n",strlen(arr));


	return 0;
}
