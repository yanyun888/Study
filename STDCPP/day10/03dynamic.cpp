/* File Name: 03dynamic.cpp
** Author: 
** Version: 
** Created Time: 15/09/16-14:20  */
 
 
#include <iostream>
using namespace std;

class A{
	virtual void foo(void){}
};
class B:public A{
	void foo(void){}
};
class C:public B{
	void foo(void){}
};
class D{
};



int main(){
	B b;
	A* pa = &b;
	cout << "pa=" << pa << endl;
	B* pb = dynamic_cast<B*>(pa);
	cout << "pb=" << pb << endl;

	//转换失败 ，返回0
	C* pc = dynamic_cast<C*>(pa);
	cout << "pc=" << pc << endl;

	//转换失败
	D* pd = dynamic_cast<D*>(pa);
	cout << "pd=" << pd << endl;

	A& ra = b;
	C& rc = dynamic_cast<C&>(ra);

	return 0;
}



