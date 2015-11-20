/*File Name: LogThread.h
**Author: 
**Version: 
**Created Time: 15/09/28-15:02  */
 
 
#ifndef _CLIENTTHREAD_H
#define _CLIENTTHREAD_H

#include "LogThread.h"

class ClientThread:public LogThread{

public:
	ClientThread(int connfd);

private:
	//线程过程
	void run(void);
	int m_connfd;
};




#endif // _LOGTHREAD_H
