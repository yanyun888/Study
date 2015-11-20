/*File Name: dataType.h
**Author: 
**Version: 
**Created Time: 15/08/13-14:44  */
 
 
#ifndef _DATATYPE_H
#define _DATATYPE_H
//定义数据类型

#define DATAWIDTH 3
//#define PROGID 100
//账户信息结构体
typedef struct account{
	//账户的名称为   随即生成的号码X  +  用户的身份证号

	char id[19];//用户的身份证号
	int idNum;//账户的编号
	//设置密码的位数 = 8
	int password;
	double money;
}account;

typedef struct msgbuf{
	long mtype;
	account acc;
	//在没有共享内存的前提下是不能直接传递指针的
}msgbuf;

typedef struct msgres{
	long mtype;
	int res;
}msgres;

#endif
