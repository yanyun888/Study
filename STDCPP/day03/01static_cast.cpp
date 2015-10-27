/* File Name: 01static_cast.cpp
** Author: 
** Version: 
** Created Time: 15/09/07-09:52  */
 
 
#include <iostream>
using namespace std;



int main(void){
	
	int *pi = NULL;
//	char c = (int)pi;
	char c = int(pi); // C++ 风格
	void *pv = pi;
	pi = static_cast<int*>(pv);
	c = static_cast<char>(pi);//error


	return 0;
}
