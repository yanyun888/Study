/*File Name: 08mem.cpp
**Author: 
**Version: 
**Created Time: 15/09/30-15:25  */
 
#include <fcntl.h>
#include <cstdio>
#include <iostream>
#include <memory>
using namespace std;
class A{
public:
	A(void) {
		cout << "构造:" << this << endl;
	}
	~A(void){
		cout << "析构:" << this << endl;
	}
};
template<typename T>
class AutoPtr{
public:
	AutoPtr(T* p = NULL) : m_p(p){}
	~AutoPtr(void)

private:
	T* m_p;
}




int foo(void){
	A* pa = new A;
	FILE* fp = fopen("none","r");

}



int main(void){
	if (foo() == -1)
		return -1;
	cout << "成功" << endl;

	return 0;
}
