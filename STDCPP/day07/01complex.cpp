/* File Name: 01complex.cpp
** Author: 
** Version: 
** Created Time: 15/09/11-09:43  */
 
 
#include <iostream>
using namespace std;


class Complex{

public:
	Complex(int r=0,int i=0):m_r(r),m_i(i){}
	void print(void){
		cout<<m_r<<"+"<<m_i<<"i"<<endl;
	}

	Complex& operator+=(const Complex& c){
		m_r+=c.m_r;
		m_i+=c.m_i;
		return *this;
	}
//全局方法
	friend const Complex operator-(const Complex& l,const Complex& r);
	friend Complex& operator-=(Complex& l,const Complex& r);
	friend ostream& operator<<(ostream& os,const Complex& c);
	/*{
		return os<<c.m_r<<'+'<<c.m_i<<'i';
	}*/
	friend istream& operator>>(istream& is,Complex& c){
		return is>> c.m_r>>c.m_i;
	}
private:
	int m_r;
	int m_i;

};

Complex& operator-= (Complex& l,const Complex& r){
	l.m_r -= r.m_r;
	l.m_i -= r.m_i;
	return l; //但是为什么不写成&l
}
const Complex operator- (const Complex& l,const Complex& r){
	return Complex(l.m_r-r.m_r,l.m_i-r.m_i);
}

ostream& operator<<(ostream& os,const Complex c){
	return os<<c.m_r<<'+'<<c.m_i<<'i'<<endl;
}
//如何在类外定义友元函数。


int main(){
	Complex c1(1,2);
	c1.print();


	return 0;
}


