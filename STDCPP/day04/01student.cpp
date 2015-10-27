/* File Name: 01student.cpp
** Author: 
** Version: 
** Created Time: 15/09/08-09:41  */
 
 
#include <iostream>
using namespace std;

class Student{

public:
	Student(void){};
	Student(const string& name,int age,int no){
		m_name = name;
		m_age = age;
		m_no = no;
	}
	void who(void){
		cout << m_name <<","<<m_age <<","<<m_no<<endl;
	}

private:
	int m_age;
	int m_no;
	string m_name;
};


int main(){

	Student s = Student("张飞",25,10011);
	s.who();

	Student* ps = new Student("张飞",25,10011);
	ps->who();

	delete ps;//手动释放内存
	Student* ps1 = new Student;

	//栈区创建多个对象
	Student sa[3] = {Student("赵云",24,10012),
		Student("马超",25,10013),
		Student("黄忠",26,10014)};
	sa[0].who();
	sa[1].who();
	sa[2].who();

	//2011新特性,在堆区创建多个对象  -std=c++0x
	Student* psa = new Student[3]{
		Student("赵云",24,10012),
		Student("马超",25,10013),
		Student("黄忠",26,10014)};

	delete[] psa;// 由于指针指向的是一个数组，所以在delete时，要加[]
}


	return 0;
}
