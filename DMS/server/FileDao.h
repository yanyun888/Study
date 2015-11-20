/*File Name: LogDao.h
**Author: 
**Version: 
**Created Time: 15/09/28-14:11  */
 
 
#ifndef _FILELOGDAO_H
#define _FILELOGDAO_H

#include <fstream>
using namespace std;
#include "LogDao.h"

//
class FileDao:public LogDao{
public:
	FileDao(string const& path) throw (DBException);

	~FileDao(void);
	void Insert(MLogRec const& log) throw (DBException);
private:
	ofstream m_ofs;
};


#endif
