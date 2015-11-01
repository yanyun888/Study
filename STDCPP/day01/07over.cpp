/* File Name: 07over.cpp
** Author: 
** Version: 
** Created Time: 15/09/02-16:00  */
 
 
#include <iostream>
using namespace std;


int foo(int a){
	cout<< "foo(int)"<<endl;
}
void foo(int a,int b){
	cout<<"foo(int,int)"<<endl;
}
double foo(void){
	cout<<"foo(void)"<<endl;
}

void foo(float a,int b){
	cout<<"foo(float,int)"<<endl;
}

void foo(int a,float b){
	cout<<"foo(int,float)"<<endl;
}

int main(){
	
	foo(10);
	foo(10,20);
	foo();
	foo(1.23f,20);

	return 0;
}
