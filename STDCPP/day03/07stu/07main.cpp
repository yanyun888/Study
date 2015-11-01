/* File Name: 07main.cpp
** Author: 
** Version: 
** Created Time: 15/09/07-17:03  */
 
 
#include <iostream>
#include "stu.h"

using namespace std;

int main(){
	
	Student s("黄忠",25,558954);
	s.who();
	s.eat("面包");
	s.learn("C++");


	return 0;
}
