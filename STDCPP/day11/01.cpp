/* File Name: 01.cpp
** Author: 
** Version: 
** Created Time: 15/09/17-09:22  */
 
 
#include <iostream>
using namespace std;

class Integer{
public:
	Integer(int r):m_r(r){}
	virtual Integer& operator+=(const Integer& i){
		m_r+=i.m_r;
		return *this;
	}
	int m_r;
};

class Complex:public Integer{
public:
	Complex(int r,int i):Integer(r),m_i(i){}
	Complex& operator += (const Integer& c){
		Integer::operator+=(c);//向上构造
		m_i += (dynamic_cast<const Complex&>(c)).m_i;
		return *this;
	}
	int m_i;

};


int main(){

	Complex c1(1,2),c2(3,4);
	Integer& i1=c1;
	Integer& i2=c2;
	i1 += i2;
	cout << c1.m_r << '+' << c1.m_i << 'j' <<endl;
	
	string s1="hello";

	cout<< s1.size() <<endl;
	return 0;
}
