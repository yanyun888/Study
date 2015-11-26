/*File Name: server.h
**Author: 
**Version: 
**Created Time: 15/08/20-10:49  */
 
 
#ifndef _SERVER_H
#define _SERVER_H

#define USR_ONLINE 1
#define USR_OFFLINE 0

#define MAXUSR 10
#define judge1(res,msg) do{if(-1 == res) perror(#msg),exit(-1);}while(0) 
#define judge2(res,msg) do{if(-1 == res) perror(#msg);}while(0) 
#define judge3(res,msg) do{if(-1 == res) {perror(#msg);continue;}}while(0)
//究竟什么语句可以使用逗号进行连接

typedef struct usr{

	int fd;	
	int state;
	char name[24];
	char ip[16];
}usr;


void init();

void shut();
void sigExit();
void usrConnect();
void* usrChat(void* pv);
void* serviceThread(void* pv);
void servSend(char* pc,size_t len,int pos);

#endif
