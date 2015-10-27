/* File Name: 05constructorException.cpp
** Author: 
** Version: 
** Created Time: 15/09/17-11:07  */
 
 
#include <iostream>
#include <cstdio>
using namespace std;

class A{
public:
	A(void){
		cout<<"A construct"<<endl;
	}
	~A(void){
		cout<<"A destruct"<<endl;
	}

};

class B{
public:
	B(void):m_a(new A){
		FILE *fp = fopen("none.txt","r");
		if(!fp){
			delete m_a;
			throw -1;
		}
		fclose(fp);
	}
	~B(void){
		delete m_a;
	}
private:
	A* m_a;
};



int main(){
	try{
		B b;
	}
	catch(int& ex){
		cout<<"错误码:"<<ex <<endl;
		return -1;
	}

	return 0;
}

