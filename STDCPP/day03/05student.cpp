/* File Name: 05student.cpp
** Author: 
** Version: 
** Created Time: 15/09/07-15:07  */
 
 
#include <iostream>
using namespace std;

class Student{

public:
	void eat(const string& food){
		cout << "我吃" << food << endl;
	}
	void learn(const string& course){
		cout << "我学" << course << endl;
	}
	
	void who(void){
		cout << "我叫" << m_name << ",今年" << m_age;
		cout << ",我是" << m_no << "号。" << endl;
	}
	//成员变量
	string m_name;
	int m_no;
	int m_age;
};


int main(){

	Student s;
	s.m_name = "张飞";
	s.m_age = 35;
	s.m_no = 10011;
	s.who();
	s.eat("拉面");
	s.learn("C++");
	return 0;
}
