/* File Name: 05diamond.cpp
** Author: 
** Version: 
** Created Time: 15/09/14-16:48  */
 
 
#include <iostream>
using namespace std;

class A{
public:
	A(int data):m_data(data){}
	int m_data;
};

class B:virtual public A{
public:
	B(int data):A(data){}
	void set(int data){
		m_data=data;
	}
};

class C:virtual public A{
public:
	C(int data):A(data){}
	int get(void){
		return m_data;
	}

};

class D:public B,public C{
public:
	D(int data):B(data),C(data),A(data){}
};


int main(){
	D d(100);
	cout << d.get()<< endl;
	d.set(200);
	cout << d.get() <<endl;

	return 0;
}

