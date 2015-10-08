/*File Name: 04template.cpp
**Author: 
**Version: 
**Created Time: 15/10/08-11:40  */
 
 
#include <iostream>
using namespace std;

class A{
public:
	template<typename T>
		void foo(T const& t){
			cout << t << endl;
		}

};

template<typename T>
void bar(T const& t){
	t.template foo<int>();
	T const* p = &t;
	p->template foo<int>();
}

int main(){

	A a;
	//a.foo();

	return 0;

};



