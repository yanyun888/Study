/* File Name: 09strstream.cpp
** Author: 
** Version: 
** Created Time: 15/09/17-14:57  */
 
 
#include <iostream>
#include <sstream>
#include <cstdio>
using namespace std;

int main(){

	int i = 1234;
	double d = 56.78;
	char c = 'T';
	char s[] = "hello world";

	//C风格
	char buf[100];
	sprintf(buf,"%d %g %c %s",i,d,c,s);
	cout << buf << endl;
	
	//C++ 风格
	ostringstream oss;
	oss << i <<' '<<d<<' '<<c<<' '<<s;
	string str = oss.str();
	cout << str << endl;

	int a;
	double b;
	char x;
	char y[100];
	
	istringstream iss;
	iss.str("100 9.99 A Hello world");
	iss >> a >> b >> x >> y;
	cout << a <<',' << b <<','<< x <<','<< y <<endl;

	return 0;
}

