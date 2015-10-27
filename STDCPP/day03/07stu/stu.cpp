/* File Name: stu.cpp
** Author: 
** Version: 
** Created Time: 15/09/07-16:54  */
 
 
#include <iostream>
#include "stu.h"
using namespace std;

Student::Student(){
	cout << "缺省构造函数" << endl;
}
Student::Student(const string& name,int age,int no){
	m_name = name;
	m_age = age;
	m_no = no;
}

void Student::eat(const string& food){
	cout << "我吃" << food << endl;
}
void Student::learn(const string& course){
	cout << "我学" << course << endl;
}
void Student::who(void){
	cout << "我叫" << m_name << ",今年" << m_age;
}
void Student::setname(const string& name){
	m_name = name;
}
void Student::setage(const int age){
	m_age = age;
}
void Student::setno(const int no){
	m_no = no;
}


