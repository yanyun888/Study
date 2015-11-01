/* File Name: 02namespace.cpp
** Author: 
** Version: 
** Created Time: 15/09/02-11:21  */
 
 
#include <iostream>
using namespace std;

namespace ns1{
	int num = 100;
	void func(void){
		std::cout << "ns1 function" << std::endl;
	}
}

namespace ns2{
	int num = 200;
	void func(void){
		std::cout << "ns2 function" << std::endl;
	}
}

int num = 300;

int main(void){

//	using namespace ns2;
//	func();
	cout << num <<endl;

//	using ns1::func;
//	func();
	//std::cout << ns1::num << std::endl;
	//std::out << num <<std::endl;
	






	return 0;
}
