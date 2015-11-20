/*File Name: LogThread.h
**Author: 
**Version: 
**Created Time: 15/09/28-15:02  */
 

#include <errno.h>
#include <cstring>
#include <iostream>
using namespace std;
#include "LogThread.h"


LogThread::~LogThread(void){

}
void LogThread::start (void) throw (ThreadException){
	int error = pthread_create(&m_tid,NULL,run,this);
	if(error)
		throw ThreadException(strerror(error));
}

void* LogThread::run(void* arg){
	pthread_detach(pthread_self()); //线程自我分离
	static_cast<LogThread*>(arg)->run();
	return NULL;
}







