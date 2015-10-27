/* File Name: 03defaultconstruct.cpp
** Author: 
** Version: 
** Created Time: 15/09/08-11:20  */
 
 
#include <iostream>
using namespace std;

class Teacher{
public:
	Teacher(const string& s ="",int age=0){
		m_name = s;
		m_age = age;
	}
	void who(void){
		cout << m_name << "," << m_age <<endl;
	}
private:
	string m_name; // 类类型
	int m_age;   // 基本类型
};

int main(){
	Teacher t;
	t.who();
	return 0;
}


