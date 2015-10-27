/* File Name: 03struct.cpp
** Author: 
** Version: 
** Created Time: 15/09/02-14:11  */
 
 
#include <iostream>
using namespace std;

struct Student{
	//成员变量
	char name[128];
	int age;

	//成员函数
	void who(void){
		cout << "我叫" << name << "，今年"<<age<<"岁。"<<endl;
	}
};


int main(void){
	struct Student s = {"张三",28};
	s.who();


	return 0;
}

