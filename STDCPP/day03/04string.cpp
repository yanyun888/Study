/* File Name: 04string.cpp
** Author: 
** Version: 
** Created Time: 15/09/07-11:45  */
 
 
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){

	string s = "hello";
	s += " world";
	cout << s << endl;

	string s2 = s;
	cout << s2 << endl;
	string s3 = "abcdefg";
	swap(s3,s2);

	cout << "s2=" << s2 << ",s3=" << s3 << endl;

	cout << s3[0] << s3[1] << s3 [2] <<endl;
	cout <<  (s==s2) << endl;
	cout << strlen(s.c_str()) <<endl;
	cout << s.length() <<endl;
	return 0;
}
