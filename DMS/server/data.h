/* File Name: data.h
** Author: 
** Version: 
** Created Time: 15/09/24-09:46  */

// 数据对象
 
#ifndef _DATA_H
#define _DATA_H
#include <unistd.h>
#include <iostream>
using namespace std;
//登入登出历史记录
struct LogRec{
	char  logname[32]; //登陆名字
	char  logip[32];   //登陆IP
	pid_t pid;         //登陆进程PID
	long  logtime;     //登入登出时间
};
struct MLogRec {
	char  logname[32]; //登陆名字
	char  logip[32];   //登陆IP
	pid_t pid;         //登陆进程PID
	long logintime;    //登入时间
	long logouttime;   // 登出时间
	long durations;    //登陆时段
	friend ostream& operator<< (ostream& os,MLogRec const& log){
		return os << log.logname <<','
			<<log.logip <<','
			<<log.pid <<','
			<<log.logintime<<','
			<<log.logouttime<<','
			<<log.durations;
			//<<endl;
	}
//全局函数和静态成员函数有什么区别
};

#endif //_DATA_H
