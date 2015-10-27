/* File Name: 05defaultconstruct.cpp
** Author: 
** Version: 
** Created Time: 15/09/08-11:38  */
 
 
#include <iostream>
using namespace std;

class A{

public:
	A(int ){//哑元参数
		cout << "A的构造函数" << endl;
	}
};


class B{

public:
	B(void){
		cout << "B的缺省构造函数" << endl;
	}
private:
	A m_a;

};

int main(){
	
	B b1;


	return 0;
}
