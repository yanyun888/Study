/* File Name: 03reinterpret.cpp
** Author: 
** Version: 
** Created Time: 15/09/07-11:13  */
 
 
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int num = 0x12345678;
	void* p = reinterpret_cast<void*>(num);
//	cout << p << endl;
	
	char text[]={"0001\00012345678\000789666"};
//	char text[]="0001\00012345678\000789666";
	printf("%s,size=%d\n",text,sizeof(text));
	printf("%c\n",text[3]);

//	cout<< text << endl;
	


	cout << "after" <<endl;
	struct T{
		char type[5];
		char acc[9];
		char passwd[7];
	};

	T* pt = reinterpret_cast<T*>(text);
	cout << pt->type << endl;
	cout << pt->acc << endl;
	cout << pt->passwd << endl;

	return 0;
}
