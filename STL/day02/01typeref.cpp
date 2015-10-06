/*File Name: 01typeref.cpp
**Author: 
**Version: 
**Created Time: 15/09/30-09:14  */
 
 
#include <iostream>
#include <typeinfo>
using namespace std;


template<typename T>
void foo(T const& x,T const& y){
	cout << typeid(x).name() << ' '
		<< typeid(y).name() << endl;
	return;
}
template<typename T>
void bar(T x,T y){
	cout << typeid(x).name() << ' '
		<< typeid(y).name() << endl;
}

template<typename A,typename B, typename C>
A hum(C arg){
	cout << typeid(A).name() << ' '
		<< typeid(B).name() << ' '
		<< typeid(C).name() << endl;
	B b;
	return A();
}


int main(){
	int a,b;
	foo(a,b);
	float c,d;
	foo(c,d);
	char e[256],f[256];
	bar(e,f); // Pc Pc
	foo(e,f); //A256_c A256_c
	//数组名的二异性
	bar("hello","STL"); //PKc PKc
//	foo ("hello","STL"); //编译错误
	hum<char,short,int>(10); //c s i
	hum<char,short>(10);    //c s i




	return 0;
}

