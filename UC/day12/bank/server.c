/*File Name: server.c
**Author: 
**Version: 
**Created Time: 15/08/13-16:48  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<signal.h>
#include"dataType.h"
#include"server.h"

int msgid1,msgid2;//1用于从c端接受数据，2用于向c端发送数据
void func(int signo){
	printf("正在关闭数据库\n");
	int res1 = msgctl(msgid1,IPC_RMID,NULL);
	int res2 = msgctl(msgid2,IPC_RMID,NULL);
	if(-1 == res1 || -1 == res2){
		perror("msgctl"),exit(-1);
		printf("数据库关闭失败\n");
	}
	else{
		printf("数据库关闭成功\n");
	}
	sleep(5);
	exit(0);
}

int main(){

	//	msgbuf msgr,msgs;//用于存放接收和发送的信号数据
	struct account acc;
	int res;
	printf("正在启动服务器端程序\n");
	serverInit(&msgid1, &msgid2);
	signal(SIGINT,func);
	while(1){
		get_msg(msgid1,&acc);
		res = dataProcess(&acc);
		send_msg(msgid2,res);
	}


	return 0;
}

//数据库初始化操作,创建两个消息队列，
void serverInit(int* p_msgid1,int* p_msgid2){
	//能否使用同一个key创建两个消息队列msgid
	key_t key1 =ftok(".",100);
	key_t key2 =ftok(".",101);
	if(-1 == key1 || -1 == key2){
		perror("ftok");
		exit(-1);
	}
	*p_msgid1 = msgget(key1,IPC_CREAT|0644);
	*p_msgid2 = msgget(key2,IPC_CREAT|0644);

	//	*p_msgid1 = msgget(key1,IPC_CREAT|IPC_EXCL|0644);
	//	*p_msgid2 = msgget(key2,IPC_CREAT|IPC_EXCL|0644);
	if(-1 == *p_msgid1 || -1 == *p_msgid2){
		perror("msgget");
		exit(-1);
	}
	printf("数据库启动成功\n");
}

//接收信号，消息队列1
int get_msg(int msgid,struct account* acc){
	msgbuf msg;
	int res = msgrcv(msgid,&msg,sizeof(msg.acc),1,0);
	if(-1 == res)	{
		perror("msgrcv");
		return -1;
	}
	*acc = msg.acc;
	return 0;
}


//调用相关的文件函数进行操作。
int dataProcess(const struct account* acc){
	char nameBuf[30];
	sprintf(nameBuf,"data/%03d%18s.dat", acc->idNum,acc->id);
	printf("name = %s\n", nameBuf);
	int fd = open(nameBuf,O_CREAT|O_RDWR,0644);
	if(-1 == fd){
		perror("open");
		return -1;
	}
	int res = write(fd,acc,sizeof(struct account));
	if(-1 == res){
		perror("write");
		return -1;
	}
	printf("数据写入成功\n");
	res = close(fd);
	if(-1 == res){
		perror("close");
		return -1;
	}
	return 0;
}

//业务完成后发送信号，消息队列2
int send_msg(int msgid,int result){
	//返回的信号通道10
	printf("正在向客户端发送信息 %d\n",result);
	msgres msg;
	msg.mtype = 10;
	msg.res = result;
	int res = msgsnd(msgid,&msg,sizeof(msg.res),0);
	if(-1 == res){
		perror("msgsnd");
		return -1;
	}
	return 0;
}

