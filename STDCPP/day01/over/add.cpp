/* File Name: add.cpp
** Author: 
** Version: 
** Created Time: 15/09/02-17:17  */
 
 
#include <iostream>
using namespace std;

extern "C"{
	int add(int num1,int num2){
		return num1+num2;
	}
}
