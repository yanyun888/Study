/* File Name: 50test.cpp
** Author: 
** Version: 
** Created Time: 15/09/17-12:03  */
 
 
#include <iostream>
using namespace std;

class A{
public:
	A(int a);
	const int& get(void){
		return m_a;
	}
private:
	int m_a;
};
A::A(int a=9):m_a(a){
	
}

int main(void){
	A a;
	cout<<"a="<<a.get()  <<endl;

}



