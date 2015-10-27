/* File Name: 10fstream.cpp
** Author: 
** Version: 
** Created Time: 15/09/17-15:14  */
 
 
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main(){

	ofstream ofs("file.txt");
	if(!ofs){
		perror("ofstream::ofstream");
	}
	ofs << 1234 << ' ' <<56.78<<' '<<"apple"<<endl;
	ofs.close();

	ifstream ifs("file.txt");
	int i;
	double d;
	string s;
	ifs >> i >> d >> s;
	cout << i <<' '<<d <<' '<<s<<endl;
	return 0;
}

