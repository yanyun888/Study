/* File Name: stu.h
** Author: 
** Version: 
** Created Time: 15/09/07-16:50  */
 
 
#ifndef _STU_H
#define _STU_H

#include <string>
using namespace std;
class Student{

public:
	Student();
	Student(const string& name, int age = 0, int no = 0);
	void eat(const string& food);
	void learn(const string& course);
	void who(void);
	void setname(const string& name);
	void setage(const int age);
	void setno(const int no);
private:
	string m_name;
	int m_age;
	int m_no;

};


#endif

