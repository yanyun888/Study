/*File Name: main.cpp
**Author: 
**Version: 
**Created Time: 15/09/29-09:18  */
 
 
#include <iostream>
using namespace std;
#include "FileDao.h"
#include "OracleDao.h"
#include "Server.h"


int main(void){
	try{
		FileDao dao("./dms.db");
//		OracleDao dao("openlab","open123");
		Server server(dao,8888);
		server.dataMine();
	}
	catch(exception& ex){
		cout << ex.what() << endl;
		return -1;
	}
	return 0;
}



