/*File Name: client.c
**Author: 
**Version: 
**Created Time: 15/08/13-15:27  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include"dataType.h"
#include"client.h"
#include"generatorId.h"

int main(){
	int serviceId = 0;
	int res;
	struct account acc;
	while(1){
		system("clear");
		mainShow();
		res = main_getServiceId(&serviceId, &acc);
		if(-1 == res){
			printf("在获取信息时出现错误，请您重新输入\n");
		}
		else{
			res = main_send(serviceId,&acc);
		}
	}
	return 0;
}
//主界面显示函数
void mainShow(){
	printf("欢迎使用银行系统\n");
	printf("[1] 开户  \n");
	printf("[2] 销户  \n");
	printf("[3] 存款  \n");
	printf("[4] 取款  \n");
	printf("[5] 查询  \n");
	printf("[6] 转帐  \n");
	printf("[0] 退出  \n");
}

//读取用户输入的信息,我们将会得到用户的身份证号码，密码，开户的余额
int main_getServiceId(int* serviceId,struct account* acc){
	printf("请输入需要办理的业务编号\n");
	scanf(" %d",serviceId);
	int res;
	switch(*serviceId){
		case 1:printf("您正在办理开户业务\n");
			   do{
				   res = getUserData(acc);
				   if(-1 == res)
					   puts("您的输入有误\n");
			   }while(-1 == res);
				acc->idNum = generatorId();
			   return 0;
		case 2:printf("您正在办理销户业务\n");
			   return 0;
		case 3:printf("您正在办理存款业务\n");
			   return 0;
		case 4:printf("您正在办理取款业务\n");
			   return 0;
		case 5:printf("您正在办理查询业务\n");
			   return 0;
		case 6:printf("您正在办理转帐业务\n");
			   return 0;
		case 0:printf("正在退出系统\n");
			   exit(0);
			   return 0;
		defult:printf("您的输入有误\n");
			   return -1;
	}

}
int getUserData(struct account* acc){
	printf("请输入您的身份证号:\n");
	scanf("%18s", acc->id);
	printf("请输入您的密码\n");
	scanf("%d", &(acc->password) );
	printf("请输入您的账户余额\n");
	scanf("%lf",&(acc->money) );

	return 0;
}

//整合信息、向服务器端发送消息队列,
int main_send(int  serviceId,const struct account* acc){
	printf("正在处理中，请稍候...\n");

	key_t key1 = ftok(".",100);//用于向服务器发送
	key_t key2 = ftok(".",101);//用于从服务器接收
	if(-1 == key1 || -1 == key2 ){
		perror("ftok");
		exit(-1);
	}
	
	int msgid1 = msgget(key1,IPC_CREAT|0644 );
	int msgid2 = msgget(key2,IPC_CREAT|0644 );
	if(-1 == msgid1 || -1 == msgid2){
		perror("msgid");
		return -1;
	}
	msgbuf msg;
	msg.mtype = serviceId;
	msg.acc = *acc;
	printf("正在向服务器发送，请稍候...\n");
	printf("您的账户为%03d%18s\n",acc->idNum,acc->id );
	int res = msgsnd(msgid1,&msg,sizeof(msg.acc),0);
	if(-1 == res){
		perror("msgsnd");
		return -1;
	}
	
	printf("正在从服务器接收，请稍候...\n");
	msgres msgr;
	res = msgrcv(msgid2,&msgr,sizeof(msgr.res),10,0);
	if(msgr.res == 0){
		printf("业务办理成功\n");
		sleep(10);
		return 0;
	}
	else{
		printf("业务办理失败\n");
		return -1;
	}

	return 0;
}

//开户的自动生成编号是放在后台进行的
