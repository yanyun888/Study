/* File Name: 07destructConstruct.cpp
** Author: 
** Version: 
** Created Time: 15/09/09-16:46  */
 
 
#include <iostream>
using namespace std;

class A{
public:
	A(void){
		cout << "A构造" << endl;
	}
	~A(void){
		cout << "A析构" << endl;
	}
};

class B{
public:
	B(void){
		cout << "B构造" << endl;
	}
	~B(void){
		cout << "B析构" << endl;
	}
	A m_a;
};

int main(){

	B b;


	return 0;
}

