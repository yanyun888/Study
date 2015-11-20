/*File Name:h2.c
**Author: 
**Version: 
**Created Time: 15/08/07-19:26  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	
	rmdir("home");
	

	int res = mkdir("home",0777);
	if(-1 == res ){
		perror("mkdir");
	}
	printf("directory created\n");
	res = chdir("home");
	if(-1 ==res ){
		perror("chdir");
	}
	printf("%s\n",(char*)get_current_dir_name());


	return 0;
}
