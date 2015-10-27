/* File Name: 53quest.cpp
 ** Author: 
 ** Version: 
 ** Created Time: 15/09/08-19:53  */


#include <iostream>
using namespace std;

class A{
public:
	A(void){ }
	void print(void){
		cout << a << endl;
		cout << b << endl;
		}
private:
	int a;
	int b;
};
class B{
public:
	void print(void){
		cout << a << endl;
	}
private:
	int a;
	A b;
};

int main(void){
	A a;
	a.print();
	B b;
	b.print();
	return 0;
}



