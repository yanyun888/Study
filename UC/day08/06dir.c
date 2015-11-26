/*File Name:06dir.c
**Author: 
**Version: 
**Created Time: 15/08/07-16:22  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

#include<dirent.h>


int main(){
	DIR* dir = opendir("../day08");
	if(NULL == dir){
		perror("open");
	}
	struct dirent* ent = readdir(dir);

	while(ent != NULL){
		printf("%d,%s\n",ent->d_type,ent->d_name);
		ent = readdir(dir);
	}

	int res = closedir(dir);
	if(-1 == res){
		perror("closedir");
	}
	return 0;
}
