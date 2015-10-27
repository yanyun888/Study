/* File Name: 01first.cpp
** Author: 
** Version: 
** Created Time: 15/09/02-10:23  */
 
 
#include <iostream>
#include <cstdio>

//using namespace std;

namespace ns2{
	int var = 0;
	void fun(void){
		int a = 10;
		std::cout << "a=" << a << std::endl;
	}
}


int main(){
	
	std::cout<<"hello world"<<std::endl;
	int number = 100;

	std::cout << number << std::endl;

	std::cin >> number;

	std::cout << number << std::endl;



	return 0;

}
