/*File Name: 05inherate.cpp
**Author: 
**Version: 
**Created Time: 15/10/08-11:52  */
 
 
#include <iostream>
#include <cstdlib>
using namespace std;

template<typename T>
class Base{
public:
	mutable int m_var;
	void fun (void) const{
		cout << m_var << endl;
	}
	void exit(int status) const{
		cout << "再见!" << endl;
	}
};

template<typename T>
class Derived: public Base<T>{
public:
	void bar(void) const{
		/*
		Base<T>::m_var = 1234;
		Base<T>::fun();
		*/
		this->m_var = 1234;
		this->fun();
		Base<T>::exit(0);
	}
};


int main(){
	Derived<int> d;
	d.bar();

	return 0;
}




