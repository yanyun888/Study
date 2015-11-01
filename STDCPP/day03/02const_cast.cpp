/* File Name: 02const_cast.cpp
** Author: 
** Version: 
** Created Time: 15/09/07-10:09  */
 
 
#include <iostream>
using namespace std;

int main(){

	//const volatile int number = 100;
	const int number = 100;
	//volatile 防止编译器做优化
	int* p = const_cast<int*>(&number);//将变量的常属性去掉
	*p=200;
	cout<< number<<','<<*p<<endl;
	cout<< reinterpret_cast<const int*>(&number)<<','<<*p<<endl;


	return 0;
}
