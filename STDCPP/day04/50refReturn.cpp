/* File Name: 50refReturn.cpp
** Author: 
** Version: 
** Created Time: 15/09/08-18:33  */
 
 
#include <iostream>
using namespace std;

int& test(int x){

	int* y=new int(x);
	cout << "y=" << y <<endl;
	return y;// 返回的是一个指针，但是函数的类型是int&
}

int main(){

	int tmp = test(5);


	return 0;
}
