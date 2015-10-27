/* File Name: 02typeid.cpp
** Author: 
** Version: 
** Created Time: 15/09/16-11:31  */
 
 
#include <iostream>
#include <typeinfo>
#include <cstring>
using namespace std;

class Student{


};


class X{
	virtual void foo(void){}
};
class Y:public X{
	void foo(void){}
};
class Z:public Y{
	void foo(void){}
};
void func(X& x){
	//if(!strcmp(typeid(x).name(),"1Y")){
	if(typeid(x)==typeid(Y)){ // 运算符重载
		cout << "这是一个Y对象" << endl;
	}
	else if(!strcmp(typeid(x).name(),"1Z")){
		cout << "这是一个Z对象" << endl;
	}

}



int main(){
	int x;
	Student s;
	cout << typeid(x).name() <<endl;
	cout << typeid(char).name() <<endl;
	cout << typeid(s).name() <<endl;
	cout << typeid(unsigned int).name() <<endl;
	cout << typeid(long long).name() <<endl;
	cout << typeid(float).name() <<endl;
	cout << typeid(double[10]).name() <<endl;
	cout << typeid(double).name() <<endl;
	cout << typeid(float*).name() <<endl;
	cout << typeid(int(*)[5] ).name() <<endl;
	
	X* px = new Y;
	cout << typeid(*px).name()<<endl;

	Y y;
	func(y);
	Z z;
	func(z);

	return 0;
}

