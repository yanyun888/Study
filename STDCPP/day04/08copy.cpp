/* File Name: 08copy.cpp
** Author: 
** Version: 
** Created Time: 15/09/08-14:43  */
 
 
#include <iostream>
using namespace std;

class A{
public:
	A(int = 0){ // 哑元
		cout << "A的缺省构造" <<endl;
		m_data = 10;
	}
	A(const A& that){
		cout << "A的拷贝构造" <<endl;
		m_data = that.m_data;
	}
	int get(void){
		return m_data;	
	}
//private:
	int m_data;
};

class B{
public:
	B(void){
		cout << "B的缺省构造" << endl;
	}
	/*
	B(const B& that){
		cout << "B的拷贝构造" << endl;
		m_a = that.m_a;
	}
	*/
	B(const B& that):m_a(that.m_a){
		cout << "B的拷贝构造函数" << endl;
	}
	void print(void){
		cout << m_a.m_data <<endl;
	}
	void setdata(int data){
		m_a.m_data = data;
	}
private:
	A m_a;
};


int main(){
/*
	A a2 = a1;
*/
	B b;
	b.setdata(100);
	b.print();
	B b2(b);
	b2.print();
	return 0;
}
