/*File Name: 01msgB.c
**Author: 
**Version: 
**Created Time: 15/08/13-11:21  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>

typedef struct {
	long mtype;//消息的类型
	char buf[20];//消息的内容
}Msg;

 


int main(){
	

	key_t key = ftok(".",100);
	if(-1 == key){
		perror("ftok");
		exit(-1);
	}
	int msgid = msgget(key,IPC_CREAT|IPC_EXCL|0644);
	if(-1 == msgid){
		perror("msgget");
		exit(-1);
	}
	printf("msgid = %d\n",msgid);
	
	Msg msg1;
	int res = msgrcv(msgid,&msg1,sizeof(msg1.buf),1,0);
	if(-1 == res){
		perror("msgrcv");
		exit(-1);
	}
	printf("type = %ld, msg = %s\n",msg1.mtype,msg1.buf);
	
	//if(-1 )


	return 0;
}
