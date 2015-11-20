/*File Name: LogThread.h
**Author: 
**Version: 
**Created Time: 15/09/28-15:02  */
 
#include <iostream>
using namespace std;
#include "LogQueue.h" 
#include "StoreThread.h"


StoreThread::StoreThread(LogDao& dao):m_dao(dao){

}
	//线程过程
void StoreThread::run(void){
	MLogRec log;
	for(;;){
		g_logQueue >> log;
		try{
			m_dao.Insert(log);
		}
		catch(DBException& ex){
			cout << ex.what() << endl;
		}
	}

}





