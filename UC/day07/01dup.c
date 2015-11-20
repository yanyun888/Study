#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
    int fd = open("a.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
    if(-1 == fd){
        perror("open");
        exit(-1);
        return 0;
    }

    int fd2 = open("b.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
    if(-1 == fd2){
        perror("open");
        exit(-1);
    }
    int fd3 = open("c.txt",O_RDONLY|O_CREAT|O_TRUNC,0644);
    if(-1 == fd3){
        perror("open");
        exit(-1);
    }
    printf("%d,%d\n",fd,fd2);
    int fd6 = dup2(fd3,2);//error--c.txt
    //	int fd5 = dup2(fd2,1);//stdout--b.txt
    int fd4 = dup2(fd,0);//stdin--a.txt
    printf("%d,%d,%d,%d\n",fd,fd2,fd3,fd4);
    write(fd2,"A",sizeof(char));
    write(fd4,"baddd",sizeof(char));
    perror("test");
    puts("test");
    char arr[10];
    scanf("%c",arr);
    printf("%c\n",arr[0]);
    int res = close(fd);
    if(-1 == fd){
        perror("close");
        exit(-1);
    }
    close(fd2);
    close(fd3);
    close(fd4);
	return 0;
}
