/* File Name: 07integer.cpp
** Author: 
** Version: 
** Created Time: 15/09/08-14:11  */
 
 
#include <iostream>
using namespace std;

class Integer{

public:
	Integer(void){
		m_data = 0 ;
	}
	explicit Integer(const int& data){
		m_data = data;
	}
	int get(void){
		return m_data;
	}


private:
	int m_data;

};



int main(){
	Integer i;
	cout << i.get() << endl;
	//i = Integer(100);//C++的强制转换
	//i = (Integer)100;
	i = static_cast<Integer>(100);//这种写法更加 
	//i = 100;
	cout << i.get() << endl;
	Integer j(i);//拷贝构造
	cout << j.get() << endl;


	return 0;
}

