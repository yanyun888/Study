/* File Name: 07refconst.cpp
** Author: 
** Version: 
** Created Time: 15/09/06-16:07  */
 
 
#include <iostream>
using namespace std;

int func(void){
	int a = 100;
	return a;
}

int func2(const int &a){
	cout << a <<endl;
	return a;
}

int main(){

	const int & r = func();
	cout << r << endl;
	int a=10,b=20;
	const int& c = a+b;
	cout << c << endl;
	func2(100);
	return 0;
}
