/* File Name: ref3.cpp
** Author: 
** Version: 
** Created Time: 15/09/06-15:14  */
 
 
#include <iostream>
using namespace std;


struct Student{
	char name[20];
	int age;
};

void print(Student& stu){//常引用
	cout<<stu.name<<","<< stu.age++<<endl;
}

int main(){
	const Student stu = {"张三",28};
	print((Student&)stu);
	print((Student&)stu);

	return 0;
}
