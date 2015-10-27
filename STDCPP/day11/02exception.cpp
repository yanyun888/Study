/* File Name: 02exception.cpp
** Author: 
** Version: 
** Created Time: 15/09/17-09:52  */
 
 
#include <iostream>
using namespace std;

class Error{

};

class MathError:public Error{

};

void foo(void){
	throw MathError();
}


int main(){
	try {
		foo();
	}
	catch(MathError& ex){
		cout<<"捕获到异常MathError"<<endl;
		return -1;
	}
	catch(Error& ex){
		cout<<"捕获到异常Error"<<endl;
		return -1;
	}


	return 0;
}

