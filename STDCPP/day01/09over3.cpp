/* File Name: 09over3.cpp
** Author: 
** Version: 
** Created Time: 15/09/02-16:43  */
 
 
#include <iostream>
using namespace std;

namespace ns1{
	void func(int a){
		cout<<"ns1:func"<< a << endl;
	}
};

namespace ns2{
	void func(double d){
		cout<<"ns2:func"<< d << endl;
	}
};

int main(){
	using namespace ns1;//外部所用域
	using namespace ns2;//
	func(10);
	func(1.23);

	using ns1::func;//引入了局部作用域,局部隐藏外部
	func(30);
	func(3.14);

	using ns2::func;
	func(50);
	func(5.64);
	return 0;
}
