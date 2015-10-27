/* File Name: 03heritancehide.cpp
** Author: 
** Version: 
** Created Time: 15/09/14-11:44  */
 
 
#include <iostream>
using namespace std;

class A{
public:
	void foo(void){
		cout << "A::foo" << endl;
	}
};

class B:public A{
public:
	void foo(int i){
		cout << "b::foo(int)" << endl;
	}
	void bar(void){
		foo(20);
		foo();
	}

	using A::foo;//而且这个foo写在后边也是没有问题的么？
};



int main(){

	B b;
	b.bar();

	return 0;
}
