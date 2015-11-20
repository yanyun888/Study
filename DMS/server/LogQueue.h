/*File Name: LogQueue.h
**Author: 
**Version: 
**Created Time: 15/09/28-14:35  */
 
 
#ifndef _LOGQUEUE_H
#define _LOGQUEUE_H

#include <pthread.h>
#include <list>
using namespace std;
#include "data.h"

class LogQueue{
public:
	LogQueue(void);
	~LogQueue(void);
	LogQueue& operator<< (MLogRec const& log);
	LogQueue& operator>> (MLogRec& log);
private:
	pthread_mutex_t m_mutex;  //同步互斥量
	
	pthread_cond_t m_full;  //非满条件量
	pthread_cond_t m_empty; //非空条件量
	
	list<MLogRec> m_logs;
	
};



extern LogQueue g_logQueue; //全局日志队列对象

#endif //_LOGQUEUE_H

