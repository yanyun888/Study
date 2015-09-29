/*File Name: 02untyped.cpp
**Author: 
**Version: 
**Created Time: 15/09/29-16:02  */
 
 
#include <iostream>
#include <cstdio>
using namespace std;
#define max(x,y) ((x)<(y)?(y):(x))

int main (void){
	
	int a = 123, b = 456;
	cout << max(a,b) << endl;
	double c = 1.23, d = 4.56;
	cout << max(c,d) << endl;
	string e = "hello" , f = "world";
	cout << max(e,f) << endl;
	char g[] = "hello" , h[] = "world";
	printf("%p,%p\n",g,h);
	cout << g <<','<<h << endl;
	cout << max(g,h) << endl;


	return 0;
}
