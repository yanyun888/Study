/* File Name: 02dumb.cpp
** Author: 
** Version: 
** Created Time: 15/09/06-10:15  */
 
 
#include <iostream>
using namespace std;


void fun(int a){
	cout<<"fun(int)"<<endl;
}

void fun(int a,int){
	cout<<"fun(int,int)"<<endl;
}

int main(){

	fun(10);
	fun(10,20);
	return 0;
}
