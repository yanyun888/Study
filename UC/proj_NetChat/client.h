/*File Name: server.h
**Author: 
**Version: 
**Created Time: 15/08/20-10:49  */
 
 
#ifndef _CLIENT_H
#define _CLIENT_H

#define USR_ONLINE 1
#define USR_OFFLINE 0

#define MAXUSR 10
#define judge1(res,msg) do{if(-1 == res) perror(#msg),exit(-1);}while(0) 
#define judge2(res,msg) do{if(-1 == res) perror(#msg);}while(0) 

typedef struct usr{

	int fd;	
	int state;
	char name[24];
	char ip[16];
}usr;


void init();
void sendName();
void shut();
void* recvMsg(void* pv);


void usrConnect();
void* usrChat(void* pv);
void* servRecv(void* pv);
void servSend(char* pc,size_t len,int pos);

#endif
