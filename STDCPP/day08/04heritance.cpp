/* File Name: 04heritance.cpp
** Author: 
** Version: 
** Created Time: 15/09/14-14:06  */
 
 
#include <iostream>
using namespace std;

class A{

public:
	int m_pub;
protected:
	int m_pro;
private:
	int m_pri;
};

class B:public A{};
class C:public A{};
class D:public A{};

int main(){



	return 0;
}


