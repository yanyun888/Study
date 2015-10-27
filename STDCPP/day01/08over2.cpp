/* File Name: 08over2.cpp
** Author: 
** Version: 
** Created Time: 15/09/02-16:16  */
 
 
#include <iostream>
using namespace std;

//char -> int 升级转换
void func(char* p,int n){
	cout<<"func(1)"<<endl;
}

//char* -> const char* 常量转换,优先于升级转换
void func(const char*p,char c){
	cout<<"func(2)"<<endl;
}

//short -> int 标准转换
void foo(char c){
	cout<<"foo(char)"<<endl;
}

//short -> int 升级转换,升级转换优先
void foo(int c){
	cout<<"foo(int)"<<endl;
}

//short -> long long 过分的升级转换
void foo(long long c){
	cout<<"foo(long long)"<<endl;
}

//省略号匹配 优先级低
void bar(double d,...){
	cout << "bar1"<< endl;
}
//需要标准转换, double -> int 
void bar(int a,int b){
	cout << "bar(int ,int)"<<endl;
}

int main(){
	char *p=NULL,c;
	func(p,c);
	short s;
	foo(s);
	bar(1.23,10);
	return 0;
}
