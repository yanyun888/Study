/*File Name: 07part.cpp
**Author: 
**Version: 
**Created Time: 15/09/30-15:03  */
 
 
#include <iostream>
using namespace std;

template<typename A,typename B>
class X{
public:
	static void print(void){
		cout << "X<A,B>" << endl;
	}

};

//局部特化(偏特化)
template<typename A>
class X<A,short>{
public:
	static void print(void){
		cout << "X<A,short>" << endl;
	}
};
//完全特化(注意和全类特化区分)
template<>
class X<short,short>{
public:
	static void print(void){
		cout << "X<short,short>" << endl;
	}
};
//针对指针的特化
template<typename A,typename B>
class X<A*,B*>{
public:
	static void print(void){
		cout << "X<A*,B*>"<< endl;
	}
};





int main(void){
	X<int , char>::print();
	X<int , short>::print();
	X<double, short>::print();
	X<int , int>::print();
	return 0;
}




