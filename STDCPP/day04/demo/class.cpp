/*File Name: class.cpp
**Author: 
**Version: 
**Created Time: 15/10/26-20:02  */
 
 
#include <iostream>
using namespace std;

class A{
public:
	A(unsigned int a=2,int aa=-1):m_aa(aa){
		m_a = a;
		cout << "construct function 2" << endl;
	}
	A(int a):m_a(a){
		cout << "construct function 1" << endl;
	}
	~A(void){
		cout << "destruct function 1" << endl;
	}
	void print(void) const{

		cout << m_a << ' ' <<m_aa << endl;
	}
private:
	int m_a;
	int m_aa;
};

int main(){
	A a(10);
	a.print();

	cout <<"---"<< endl;
	A b;
	b.print();

	return 0;
}

