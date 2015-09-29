/*File Name: 03macro.cpp
**Author: 
**Version: 
**Created Time: 15/09/29-16:16  */
 
 
#include <iostream>
using namespace std;
#define MAX(T)\
T max_##T (T x,T y){\
return x < y ? y : x;\
}

MAX(int)
MAX(double)
MAX(string)

#define max(T) max_##T

int main(void){

	int a = 123, b = 456;
	cout << max(int) (a,b) << endl;

	double c = 123, d = 456;
	cout << max(double) (a,b) << endl;

	string e = "hello", f = "world" ;
	cout << max(string) (e,f) << endl;


	return 0;
}
