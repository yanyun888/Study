/* File Name: 08ref4.cpp
** Author: 
** Version: 
** Created Time: 15/09/06-16:41  */
 
 
#include <iostream>
using namespace std;

struct A{
	int data;
	int& func(void){
		return data;
	}
};


int& func2(void){
	int data = 100;
	return data;
}
int& func3(void){
	int data = 1000;
	return data;
}

int main(void){
	
	A a={10};
	cout << a.data <<endl;
	a.func()=20;
	cout << a.data <<endl;
	int& b=func2();
	cout << b <<endl;
	func3();
	cout << b <<endl;



	return 0;
}
