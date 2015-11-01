/* File Name: 01defaultargs.cpp
** Author: 
** Version: 
** Created Time: 15/09/06-09:52  */
 
 
#include <iostream>
using namespace std;


void func(int a,int b=200,int c=300);
void func(int num){
	cout<<num<<endl;
}


int main(){

	func(1,2,3);
	func(1,2);
	
	//func(3);


	return 0;
}




void func(int a,int b,int c){
	cout<<a<<" "<<b<<" "<<c<<" "<<endl;
}
