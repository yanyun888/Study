/*File Name: client.h
**Author: 
**Version: 
**Created Time: 15/08/13-15:02  */
 
 
#ifndef _CLIENT_H
#define _CLIENT_H
#include"dataType.h"

//主界面显示函数
void mainShow();

//读取用户输入的信息,我们将会得到用户的身份证号码，密码，开户的余额
int main_getServiceId(int* serviceId,struct account* acc);
int getUserData(struct account* acc);

//整合信息、向服务器端发送消息队列,
int main_send(int serviceId,const struct account* acc);
//开户的自动生成编号是放在后台进行的




#endif
