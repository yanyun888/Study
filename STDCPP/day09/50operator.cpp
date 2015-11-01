/* File Name: 50operator.cpp
** Author: 
** Version: 
** Created Time: 15/09/15-09:29  */
 
 
#include <iostream>
using namespace std;

class Complex{
public:
	Complex(int r=0,int i=0):m_r(r),m_i(i){}
	void print(void) const{
		cout << m_r << '+' << m_i << 'j' <<endl;
	}
	const Complex operator+(const Complex& that) const{
		return Complex(m_r+that.m_r,m_i+that.m_i);
	}
	const Complex operator-(const Complex& that) const{
		return Complex(m_r-that.m_r,m_i+that.m_i);//返回类时的返回值是一个左值，匿名类变量。
	}
	Complex& operator+=(const Complex& that){
		m_r += that.m_r;
		m_i += that.m_i;
		return *this;
	}
	Complex& operator-=(const Complex& that){
		m_r -= that.m_r;
		m_i -= that.m_i;
		return *this;
	}
	Complex& operator++(void){ //这里是前++运算符
		m_r++;
		m_i++;
		return *this;
	}
	Complex operator++(int){ //这里时后++运算符
		Complex old = *this;
		m_r++;
		m_i++;
		return old;
	}
	//Complex operator


	friend ostream& operator<<(ostream& os,const Complex& that);
	friend istream& operator>>(istream& is,Complex& that);


private:
	int m_r;
	int m_i;
};

//友元函数的名称，返回值，参数表，必须严格相同
ostream& operator<<(ostream& os,const Complex& that){
	return os<<that.m_r<<'+'<<that.m_i<<'j';
}

istream& operator>>(istream& is,Complex& that){
	return is>>that.m_r>>that.m_i;
}

int main(){
	Complex c1(1,2);
	Complex c2(3,4);
	Complex c3;
	c1.print();
	c2.print();
/*
	c3=c1+c2;
	c3.print();
	c3+=c1;
	c3.print();
*/
	++c3;
	c3.print();
//如何验证后++
	Complex c4=c3++;
	c3.print();
	c4.print();
	cout <<"c4:" <<c4 <<endl;
	cin >> c4;
	c4.print();

	return 0;
}

