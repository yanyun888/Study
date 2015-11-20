/*************************************************************************
	> File Name: 04flock.c
	> Author:Samson
	> Mail:
	> Created Time: 2015年08月06日 星期四 15时26分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(){
    
    int fd = open("a.txt",O_RDWR);
    if(-1 == fd){
        perror("open");
        exit(-1);
    }
    int res = write(fd,"hello",5);
    if(-1 == res){
        perror("write");
    }
    printf("write succeed, size = %d\n",res);
    res = close(fd);
    if(-1 == res){
        perror("close");
    }

    return 0;
}
