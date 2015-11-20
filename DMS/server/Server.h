/*File Name: server.h
**Author: 
**Version: 
**Created Time: 15/09/29-09:16  */
 
 
#ifndef _SERVER_H
#define _SERVER_H

#include <except.h>
#include <LogDao.h>
//#include <>

class Server{

public:
	Server(LogDao& dao,short port,string const& ip = "") throw (ServerException);
	dataMine();
private:



};



#endif //_SERVER_H
