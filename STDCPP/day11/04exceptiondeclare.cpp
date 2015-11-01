/* File Name: 04exceptiondeclare.cpp
** Author: 
** Version: 
** Created Time: 15/09/17-10:19  */
 
 
#include <iostream>
using namespace std;

class FileError{

};
class MemoryError{

};

void foo(void) throw(FileError,MemoryError){//
	throw -1;
	throw FileError();
}


int main(){
	try{
		foo();
	}
	catch(FileError ex){
		cout<<"文件错误"<<endl;
		return -1;
	}
	catch(MemoryError ex){
		cout<<"内存错误"<<endl;
		return -1;
	}
	catch(...){
		cout<<"其他错误"<<endl;
		return -1;
	}
	return 0;
}

