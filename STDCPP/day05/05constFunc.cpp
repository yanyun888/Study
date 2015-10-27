/* File Name: 05constFunc.cpp
** Author: 
** Version: 
** Created Time: 15/09/09-14:50  */
 
 
#include <iostream>
using namespace std;

class A{
public:
	A(int data=0):m_data(data){}
	void show(void) const{
		cout << m_data++ << endl;
	}
private:
	mutable int m_data;
};



int main(){

	A a(100);
	a.show();
	a.show();

	return 0;
}


