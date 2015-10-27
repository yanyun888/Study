/* File Name: 05bool.cpp
** Author: 
** Version: 
** Created Time: 15/09/02-14:52  */
 
 
#include <iostream>
using namespace std;

int main(){

	bool b = false;

	cout << b << ",size:" << sizeof(b) << endl;

	b = 100;
	cout << b << ",size:" << sizeof(b) << endl;
	b = 0.0;
	cout << boolalpha << b << ",size:" << sizeof(b) << endl;
	b = "hello world";
	cout << b << ",size:" << sizeof(b) << endl;
	b = NULL;
	cout << b << ",size:" << sizeof(b) << endl;
	return 0;

}
