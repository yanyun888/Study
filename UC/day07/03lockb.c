/*************************************************************************
	> File Name: 03lockb.c
	> Author:Samson
	> Mail:
	> Created Time: 2015年08月06日 星期四 14时48分08秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(){
    int fd = open("a.txt",O_RDWR);
    if(-1 == fd){
        perror("open");
        exit(-1);
    }
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 10;
    lock.l_pid = -1;
        
    int res = fcntl(fd,F_SETLKW,&lock);
    if(-1 == res){
        perror("fcntl");
        //exit(-1);
    }
    else{
        printf("uing file a.txt\n");
        printf("lock succeed\n");
    }

    res = close(fd);
    if(-1 == res){
        perror("close");
        exit(-1);
    }

    return 0;
}
