/* File Name: 06destructorException.cpp
** Author: 
** Version: 
** Created Time: 15/09/17-11:29  */
#include <iostream>
using namespace std;
class A{
public:
	void foo(void){
		throw -2;
	}
	~A(void){
		cout<<"A析构"<<endl;
		throw -1;
	}
};
int main(){
	try{
		A a;
		a.foo();
	}
	catch(int& ex){
		cout<<"异常："<<ex<<endl;
		return -1;
	}
	return 0;
}
