/* File Name: union.cpp
** Author: 
** Version: 
** Created Time: 15/09/02-14:20  */
 
 
#include <iostream>
#include <cstdio>
using namespace std;

int main(){

	union{
		unsigned int un;
		unsigned char uc[4];
	};

	un = 0x12345678;

	for(int i=0;i<4 ;i++){
		printf("%#x\n",uc[i]);
//		cout<<uc[i]<<endl;

	}


	return 0;
}
