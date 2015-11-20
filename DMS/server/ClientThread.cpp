/*File Name: LogThread.h
**Author: 
**Version: 
**Created Time: 15/09/28-15:02  */
 
 
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
using namespace std;
#include "ClientThread.h"

#include "LogQueue.h"

ClientThread::ClientThread(int connfd):m_connfd(connfd){
}

void ClientThread::run(void){
	MLogRec log;
	
	for(;;){
		ssize_t rlen = 0;
		for(size_t len = sizeof(log);len;len-=rlen)
			rlen = recv(m_connfd,(char*)&log + sizeof(log) - len,len,0);
		//这种做法针对的是每次受到的会不足sizeof(log)
		if (rlen <= 0)
			goto escape;
		//	break;
		log.pid        = ntohl (log.pid);
		log.logintime  = ntohl (log.logintime);
		log.logouttime = ntohl (log.logouttime);
		log.durations  = ntohl (log.durations);
		g_logQueue << log;
	}
escape:
	close (m_connfd);
	delete this; //对象自毁

}




