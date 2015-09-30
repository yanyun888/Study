/*File Name: 05array.cpp
**Author: 
**Version: 
**Created Time: 15/09/30-11:55  */
 
 
#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T>
class A{
public:
	T m_a;
};

template<typename T>
class B{
public:
	T m_b;
};



int main(void){
	A<int> ai;
	B<int> bi;
	B< A<int> > ba;
	cout << typeid(ba).name() << endl;
	cout << typeid(bi).name() << endl;
	cout << typeid(ba.m_b.m_a).name() << endl;
	A<A<int> > aa;
	cout << typeid(aa).name() << endl;
	return 0;
}

