/* File Name: 01destroy.cpp
** Author: 
** Version: 
** Created Time: 15/09/16-11:13  */
 
 
#include <iostream>
using namespace std;

class Base{

public:
	Base(void){
		cout << "Base构造" << endl;
	}
	virtual ~Base(void){
		cout << "Base析构" << endl;
	}
};
class Derived:public Base{
public:
	Derived(void){
		cout << "Derived构造" << endl;
	}
	~Derived(void){
		cout << "Derived析构" << endl;
	}

};

int main(){

	Base* pb = new Derived;
	delete pb;


	return 0;
}


