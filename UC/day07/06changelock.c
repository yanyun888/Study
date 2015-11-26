/*************************************************************************
> File Name: 06changelock.c
> Author:
> Mail:
> Created Time: 2015年08月06日 星期四 16时35分11秒
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
    }
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 10;
    lock.l_pid = getpid();
    int res = fcntl(fd,F_SETLKW,&lock);
    if(-1 == res){
        perror("lock");
    }
    else{
        printf("lock is on\n");
        sleep(20);
    }
    lock.l_type = F_UNLCK;
    res = fcntl(fd,F_SETLKW,&lock);
    if(-1 == res){
        perror("lock");
    }
    else{
        printf("lock is off\n");
        sleep(20);
    }
    res = close(fd);
    if(-1 == res){
        perror("close");
    }
    printf("finish\n");
    return 0;
}
