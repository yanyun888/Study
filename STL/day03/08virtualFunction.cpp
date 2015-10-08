/*File Name: 08virtualFunction.cpp
**Author: 
**Version: 
**Created Time: 15/10/08-15:30  */
 
 
#include <iostream>
using namespace std;

template<typename T>
class A{
public:
	virtual void foo(T const& t) const{
		cout << "A::foo("<<t<<')'<< endl;
	}
	virtual T bar(void) const{
		cout << "A::bar()" <<endl;
		return T();
	}

};

template<typename U>
class B : public A<U>{
public:
	void foo(U const& u) const {
		cout << "B::foo(" << u << ')' << endl;
	}
	virtual U bar (void) const {
		cout << "B::bar()" << endl;
		return U();
	}


};


class C{
public:
	template<typename T>
/*	virtual */void hum(void) const {}
};



int main(void){
	B<int> bi;
	A<int>& ai = bi;
	ai.foo(100);
	//A<double>& ad=bi;
	cout << ai.bar()<<endl;

	return 0;
}




