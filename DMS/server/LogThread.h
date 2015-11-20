/*File Name: LogThread.h
**Author: 
**Version: 
**Created Time: 15/09/28-15:02  */
 
 
#ifndef _LOGTHREAD_H
#define _LOGTHREAD_H

#include <pthread.h>
#include "except.h"

class LogThread{

public:
	virtual ~LogThread(void);
	void start (void) throw (ThreadException);

private:
	//线程过程
	static void* run(void* arg);
	virtual void run(void) = 0;
	pthread_t m_tid;
};




#endif // _LOGTHREAD_H
