/*File Name: 01msgA.c
**Author: 
**Version: 
**Created Time: 15/08/13-10:20  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<signal.h>

typedef struct {
	long mtype;//消息的类型
	char buf[20];//消息的内容
}Msg;

void func(int signo,siginfo_t* info,void* p){
	printf("signo = %d\n",signo);
	printf("正在删除消息队列\n");
/*	int res = msgctl(msgid,IPC_RMID,NULL);
	if(-1 == res){
		perror("msgctl");
		exit(-1);
	}
	printf("删除消息队列成功，进程结束");
	*/
	exit(0);
}


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
	
	Msg msg1,msg2;
	msg1.mtype = 2;
	strcpy(msg1.buf,"hello2");
	msg2.mtype = 1;
	strcpy(msg2.buf,"hello1");
	int res = msgsnd(msgid,&msg1,sizeof(msg1.buf),0);
	if(-1 == res){
		perror("msgsnd");
		exit(-1);
	}
	res = msgsnd(msgid,&msg1,sizeof(msg1.buf),0);
	if(-1 == res){
		perror("msgsnd");
		exit(-1);
	}
	puts("发送消息到队列中成功");

	//利用ctrl+c来删除消息队列
	//使用全局变量实现数据的传递，为什么不用sigaction实现数据的传递呢
	//使用sigaction进行数据的传递需要使用sigqueue来实现，
	struct sigaction action;
	action.sa_sigaction = func;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask,3);

	int sa_flags = SA_SIGINFO | SA_RESETHAND;
	

	res = sigaction(SIGINT,&action,NULL);
	if(-1 == res){
		perror("signal");
		exit(-1);
	}


	puts("删除消息队列请按Ctrl + C");
	while(1);
	return 0;
}
