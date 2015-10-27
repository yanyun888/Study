/* File Name: 01new.cpp
** Author: 
** Version: 
** Created Time: 15/09/14-09:24  */
 
 
#include <iostream>
#include <cstdlib>
using namespace std;

class A{
public:
	A(void){
		cout << "A::A()" <<endl;
	}
	~A(void){
		cout << "A::~A()" <<endl;
	}
	static void* operator new(size_t size){
		void* pv = malloc(size);
		cout << pv << endl;
		return pv;
	}
	static void operator delete(void* pv){
		cout << "A::delete(" <<pv<<")"<< endl;
		free(pv);//void* 指针能够free么
	}
};

int main(){

	A* pa = new A;//这里的new操作符无参数
	cout << "pa=" << pa << endl;
	delete pa;


	return 0;
}

