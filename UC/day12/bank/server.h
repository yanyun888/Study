/*File Name: server.h
**Author: 
**Version: 
**Created Time: 15/08/13-15:19  */
 
 
#ifndef _SERVER_H
#define _SERVER_H

#include"dataType.h"

//数据库初始化操作,创建两个消息队列，
void serverInit(int* p_msgid1,int* p_msgid2);

//接收信号，消息队列1
int get_msg(int msgid,struct account* acc);

//调用相关的文件函数进行操作。
int dataProcess(const struct account* acc);

//业务完成后发送信号，消息队列2
int send_msg(int msgid,int res);


#endif
