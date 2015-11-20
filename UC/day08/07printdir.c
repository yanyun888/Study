/*File Name:07printdir.c
**Author: 
**Version: 
**Created Time: 15/08/07-16:46  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>

void print(char* path,int depth){
	if(NULL == path){
		return ;
	}
	DIR* dir = opendir(path);
	if(NULL == dir)
		return ;
	struct dirent* pd;
	while((pd = readdir(dir))!= NULL){
		if(4 == pd->d_type){
			printf("%*s%s(%d)\n",depth,"",pd->d_name,pd->d_type);
			if(!strcmp(pd->d_name,".") || !strcmp(pd->d_name,"..") )
				continue;
			char buf[100];
			sprintf(buf,"%s/%s",path,pd->d_name);
			print(buf,depth+1);
		}
		if(8 == pd->d_type)
			printf("%*s%s(%d)\n",depth," ",pd->d_name,pd->d_type);
	}


}

int main(){
	print("../../uc",0);
	return 0;
}
