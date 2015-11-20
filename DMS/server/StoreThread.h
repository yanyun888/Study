/*File Name: LogThread.h
**Author: 
**Version: 
**Created Time: 15/09/28-15:02  */
 
 
#ifndef _STORETHREAD_H
#define _STORETHREAD_H
#include "LogThread.h"
#include "LogDao.h"

class StoreThread:public LogThread{

public:
	StoreThread(LogDao& dao);
private:
	//线程过程
	void run(void) = 0;
	LogDao& m_dao;

};




#endif // _STORETHREAD_H
