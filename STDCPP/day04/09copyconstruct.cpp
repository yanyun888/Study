/* File Name: 09copyconstruct.cpp
** Author: 
** Version: 
** Created Time: 15/09/08-16:15  */
 
 
#include <iostream>
using namespace std;

class A{
public:
	A(void){}
	A(const A& that){//拷贝构造必须写成引用，而且是常量引用
		cout << "A的拷贝构造函数" << endl;
	}
};

//void func(const A& a){}

void func(A a){

}

A func2(void){
	A a;
	cout << &a << endl;
	return a;//从函数返回对象，构造过程可能被优化
}

int main(){

	A a1;
	A a2(a1);
	func(a2);//实参到形参的拷贝

	A a3 = func2();
	cout << &a3 << endl;

	return 0;
}


