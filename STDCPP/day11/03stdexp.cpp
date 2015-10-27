/* File Name: 03stdexp.cpp
** Author: 
** Version: 
** Created Time: 15/09/17-10:05  */
 
 
#include <iostream>
using namespace std;

class FileError:public exception{
public:
	const char* what(void)const throw(){
		return "文件访问失败";
	}

};

int main(){
	try{
		throw FileError();
		char* p = new char[0xffffffff];
	}
	catch(exception& ex){
		cout<<"ex="<<ex.what()<<endl;
		return -1;
	}
	return 0;
}

