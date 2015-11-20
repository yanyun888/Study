/*File Name: LogDao.h
**Author: 
**Version: 
**Created Time: 15/09/28-14:11  */
 
 
#ifndef _ORACLEDAO_H
#define _ORACLEDAO_H

#include <fstream>
using namespace std;
#include "LogDao.h"

//
class OracleDao:public LogDao{
public:
	OracleDao(string const& username,string const& password) throw (DBException);

	~OracleDao(void);
	void Insert(MLogRec const& log) throw (DBException);
private:

};


#endif //ORACLEDAO_H
