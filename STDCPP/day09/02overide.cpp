/* File Name: 02overide.cpp
** Author: 
** Version: 
** Created Time: 15/09/15-11:17  */
 
 
#include <iostream>
using namespace std;

class A{

};
class B:public A{

};


class Base{
public:
	virtual void foo(void){
		cout<<"Base::foo"<<endl;
	}
	virtual void bar(void){
		cout << "Base::bar" <<endl;
	}
	virtual void pub(void){
		cout << "Base::pub" <<endl;
	}

};
class Derived:public Base{
public:
	void foo(void){
		cout << "Derived::foo" <<endl;
	}
	void bar(int x){
		cout<<"Derived::bar(int)" <<endl;
	}
public:
	virtual void pub(void){
		cout << "Derivated::pub" <<endl;
	}

};

int main(){
	Derived d;

	Base &b = d;
	b.foo();
	b.bar();
	d.bar(5);

	return 0;
}

