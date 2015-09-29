/*File Name: 04ftmpl.cpp
**Author: 
**Version: 
**Created Time: 15/09/29-16:29  */
 
 
#include <iostream>
using namespace std;

//函数模板
template<typename T>
T max(T x,T y){
	return x < y ? y : x;
}

class Student{
public:
	Student (string const& name,int age):
		m_name(name),m_age(age){}
	bool operator<(Student const& rhs)const{
		return m_age < rhs.m_age;
	}
	friend ostream& operator<< (ostream& os, Student const& s){
		return os<<s.m_name<<','<<s.m_age;
	}
private:
	string m_name;
	int m_age;
};

int main(void){
	int a = 123, b = 456;
	cout << ::max<int>(a,b) << endl;
	//为了区分模板库和自定义模板max 在函数名字前加::
	cout << ::max<double>(1.23,4.56) << endl;
	char c[] = "hello" , d[]="world";
	cout << ::max<string>(c,d)<< endl;
	cout << std::max<int>(1234,5678) << endl;
	Student s1("abc",24),s2("def",25);
	cout << ::max<Student>(s1,s2) << endl;

	return 0;
}

