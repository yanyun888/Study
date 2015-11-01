/* File Name: 50ptr_over.cpp
** Author: 
** Version: 
** Created Time: 15/09/07-14:07  */
#include <iostream>

void print(char c){
	std::cout << "c = " << c << std::endl;
}

void print(int n){
	std::cout << "n = " << n << std::endl;
}

int main(int argc, const char * argv[]){
	void (*pfn1)(char c) = print;
	void (*pfn2)(int n) = print;
	pfn1('a');
	pfn2(10);
	return 0;
}
