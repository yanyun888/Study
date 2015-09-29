/*File Name: 01type.cpp
**Author: 
**Version: 
**Created Time: 15/09/29-15:33  */
 
 
#include <iostream>
#include <string>
using namespace std;

int int_max(int x,int y){
	return x < y ? y : x;
}
double double_max(double x,double y){
	return x < y ? y : x;
}
string string_max(string x,string y){
	return x< y ? y : x;
}

int main(void){
	int a = 123,b=456;
	cout << int_max(a,b) << endl;
	double c = 123,d=456;
	cout << double_max(c,d) << endl;
	string e = "hello",f="world";
	cout << string_max(e,f) << endl;
	return 0;
}
