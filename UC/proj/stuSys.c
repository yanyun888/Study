#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include"stuSys.h"
int addData(int fd,STU* pSTU){
    if(NULL == pSTU){
        printf("ptr is NULL\n");
        return -1;
    }
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_CUR;
    lock.l_start = 0;
    lock.l_len = sizeof(STU);
    lock.l_pid = -1;
    //对文件加写操作
    int res = fcntl(fd,F_SETLKW,&lock);
    if(-1 == res){
        perror("write lock failed");
        return -1;
    }
    else{
        write(fd,pSTU,sizeof(STU));
    }
    return 0;
}
int getStu(STU* pSTU){
	//从键盘获取一个学生的信息
	//
	return 0;
}
//删除某一个编号的信息
int delData(int fd,int id){
    int res = getData(fd,id);
    if(-1 == res){
        return -1;
    }
	//在getdata查找过后，文件表指针的位置位于所需要数据的开头位置
    struct STU stuTemp;
    lseek(fd,-sizeof(STU),SEEK_END);
	read(fd,&stuTemp,sizeof(STU));
    lseek(fd,res,SEEK_SET);
    write(fd,&stuTemp,sizeof(STU));
   //剩下的为文件截取操作，那么如果对文件进行截取，舍弃掉最后的重复数据呢？ 
	res = lseek(fd,0,SEEK_END);
	res -= sizeof(STU);
	if(res < 0)
		res = 0;
	res = ftruncate(fd,res);
	if(-1 == res){
		perror("ftruncate");
		return -1;
	}
    printf("data del succeed\n");
    return 0;
}
//获取编号信息
int getData(int fd,int id){
	
    int res = lseek(fd,0,SEEK_SET); 
    if(-1 == res){
        perror("lseek");
    }
    //加文件锁，读锁
    do{
    STU stuTemp;
    res = read(fd,&stuTemp,sizeof(STU));
    if(stuTemp.id == id)
        break;
    }while(res!=0);
    if(0 == res){
        printf("NO.%d is not found\n",id);
        return -1;
    }
    lseek(fd,-sizeof(STU),SEEK_SET);
}
//打印每一个编号的信息
void printData(int fd){
    lseek(fd,0,SEEK_SET);
}
