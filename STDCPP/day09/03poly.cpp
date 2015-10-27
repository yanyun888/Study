/* File Name: 03poly.cpp
** Author: 
** Version: 
** Created Time: 15/09/15-14:12  */
 
 
#include <iostream>
using namespace std;

class Base{
public:
	Base(void){
		this->foo();// 子类实际上未构造出来
	}

	~Base(void){
		this->foo();// 子类已经被析构掉了
	}

	virtual int cal(int x,int y){
		return x+y;
	}
	virtual void bar(void){
		cout << "Base::bar()" <<endl;
	}
	void foo(void){
		bar();//this 指针也是指针
	}
};

class Derived:public Base{
public:
	int cal(int x,int y){
		return x*y;
	}
	void bar(void){
		cout << "Derived::Bar()"<<endl;
	}

};


int main(){
	
	Derived d;
	Base b = d;  //这里叫隐式转换么？
//	cout << b.cal(100,200) << endl;
	d.foo();
	Base* pb = &d;
	//必须通过指针或引用才能表现出多态的特性。
	cout <<pb->cal(100,200) << endl;


	return 0;
}

