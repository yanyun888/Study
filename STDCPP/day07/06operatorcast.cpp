/* File Name: 06operatorcast.cpp
** Author: 
** Version: 
** Created Time: 15/09/11-16:37  */
 
 
#include <iostream>
#include <cstdio>
#include <cstring>
//#include 
using namespace std;

class Integer{
public:
	explicit Integer(int data=0):m_data(data){}
	/* explicit */ operator int(void) const{//类型转换函数
		return m_data;
	}
private:
	int m_data;
};
class Student{
public:
	Student(const string&name,int age):m_name(name),m_age(age){}
	operator string(void) const{
		char str[100]={0};
		sprintf(str,"%s,%d",m_name.c_str(),m_age);//c_str将string转换为char*
		return str;//string 可以直接接收str
	}
private:
	string m_name;
	int m_age;
};


int main(){
	Integer i1;
	i1 = static_cast<Integer>(100);//单参构造函数
	cout << i1 <<endl;
	int i2 = i1;
	cout << i2 <<endl;
	Student s("张飞",25);
	cout << string(s)<<endl;

	return 0;
}

