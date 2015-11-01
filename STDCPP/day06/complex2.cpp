#include <iostream>
using namespace std;

class Complex{
public:
	Complex(int r=0,int i=0):m_r(r),m_i(i){}
	void print(void)const{
		cout << m_r << '+' << m_i << 'i' << endl;
	}
	/*从左到右const
	  第一个：修饰返回值,返回常对象禁止对表达式赋值
	  第二个：支持常量型右操作数
	  第三个：支持常量型左操作数（常函数）
	 */
	const Complex operator+(const Complex& c)const{
		return Complex(m_r+c.m_r,m_i+c.m_i);
	}
private:
	int m_r;
	int m_i;
};
int main(void)
{
	const Complex c1(1,2);
	const Complex c2(3,4);
	c1.print();
	c2.print();
	Complex c3 = c1 + c2;//c3=c1.operator+(c2)
	c3.print();
	//(c1+c2)=c3;
	return 0;
}

