/* File Name: 06construct.cpp
** Author: 
** Version: 
** Created Time: 15/09/07-16:20  */
 
 
#include <iostream>
using namespace std;

class Student{

public:
	Student(){
		cout << "缺省构造函数" <<endl;
		m_age = 0;
		no = 0;
	}
	Student(const string& name, int age = 0, int no = 0){
		cout << "调用了构造函数" << endl;
		m_name = name;
		m_age = age;
		m_no = no;
	}
private:
	string m_name;
	int m_age;
	int m_no;

};

int main(){

	Student s("刘备",35,54589);
	Student s1;
	Student s2("曹操");
	cout << "size = "<<sizeof(s1) <<endl;
	cout << "sizeof(string) = " << sizeof(string) << endl;

	return 0;
}
