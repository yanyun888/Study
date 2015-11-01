/* File Name: 06construct.cpp
** Author: 
** Version: 
** Created Time: 15/09/08-11:49  */
 
 
#include <iostream>
using namespace std;

class C{
public:
	C(int data){
		m_data = data;
	}
	void print(void){
		cout << "m_data=" << m_data <<endl;
	}
private:
	int m_data;
};

class D{
public:
	//如果C类不能使用无参构造，可以使用下面方法显式的说明m_c子对象的构造方式
	D(void):m_c(100){}  
	void print(void){
		m_c.print();
	}
private:
	C m_c;
};



int main(){

	D d;
	d.print();


	return 0;
}

