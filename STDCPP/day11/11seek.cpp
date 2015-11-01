/* File Name: 11seek.cpp
** Author: 
** Version: 
** Created Time: 15/09/17-16:11  */
 
 
#include <iostream>
#include <fstream>
using namespace std;




int main(){
	fstream fs("seek.txt",ios::in|ios::out);
	fs << "0123456789";
	cout << fs.tellp() << endl;
//	cout << fs.tellg() << endl;
	fs.seekg(-3,ios::cur);
	fs << "XYZ";
	cout << fs.tellg() << endl;
	fs.seekg(3,ios::beg);
	string s;
	fs >> s;
	cout << s << endl;

	
	return 0;
}

