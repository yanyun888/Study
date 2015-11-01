/* File Name: 04square.cpp
** Author: 
** Version: 
** Created Time: 15/09/11-15:27  */
 
 
#include <iostream>
using namespace std;

class Square{
public:
	double operator()(double x)const{
		return x*x;
	}
	int operator()(int a,int b,int c)const{
		return a+b-c;
	}
private:


};


int main(){



	return 0;
}

