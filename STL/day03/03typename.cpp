/*File Name: 03typename.cpp
**Author: 
**Version: 
**Created Time: 15/10/08-11:21  */
 
 
#include <iostream>
using namespace std;

class A{
public:
	typedef unsigned int UNIT;
	class B{};
private:
};

void foo(void){
	A::UNIT u;
	A::B b;
}
//template<typename T>


int main(){
	return 0;
}
