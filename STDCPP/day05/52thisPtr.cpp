/* File Name: 52thisPtr.cppd
** Author: 
** Version: 
** Created Time: 15/09/09-10:19  */
 
 
#include <iostream>
using namespace std;

class Integer{
public:
	Integer(const int& integer):m_value(integer){
	}
	Integer add(const Integer& that ){
		m_value += that.m_value;
		return *this;
	}
	Integer& inc(void){
		++m_value;
		return *this;//返回值是引用,目的为跳过拷贝构造函数么?
	}
	void show(void){
		cout << m_value << endl;
	}
private:
	int m_value;
};

int main(){

	Integer num(15);
	num.add(5);
	num.show();
	num.inc().inc();
	num.show();



	return 0;
}

