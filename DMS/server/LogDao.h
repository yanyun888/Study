/*File Name: LogDao.h
**Author: 
**Version: 
**Created Time: 15/09/28-14:11  */
 
 
#ifndef _LOGDAO_H
#define _LOGDAO_H

#include "data.h"
#include "except.h"

//
class LogDao{
public:
	virtual ~LogDao(void){}
	virtual void Insert(MLogRec const& log) throw (DBException) = 0;
};


#endif
