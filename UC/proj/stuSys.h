/**********************************************************
  > File Name: stuSys.h
  > Author:
  > Mail:
  > Created Time: 2015年08月06日 星期四 19时46分37秒
 *********************************************************/
#ifndef _STUSYS_H
#define _STUSYS_H 1
typedef struct STU{
    char name[20];
    int id;
    int score1;
}STU;
//打开一个文件
int openFile(const char* str);
//增加一个信息
int addData(int fd,STU* pSTU);
//从键盘获得一个学生的信息
int getStu(STU* pSTU);
//删除某一个编号的信息
int delData(int fd,int id);
//获取编号信息
int getData(int fd,int id);
//打印一个编号的信息
void printData(int fd);
//int lockFile(int fd,int mode);
#endif
