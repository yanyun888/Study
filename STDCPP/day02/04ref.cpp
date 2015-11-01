/* File Name: 04ref.cpp
** Author: 
** Version: 
** Created Time: 15/09/06-11:53  */
 
 
#include <iostream>
using namespace std;

int main(){
	int a = 100;
	int& b = a;

	cout<<"a="<< a << "," << &a <<endl;
	cout<<"b="<< b << "," << &b <<endl;


	return 0;
}
