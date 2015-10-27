#include <iostream>
using namespace std;
class Student{
public:
	Student(const string& name = ""):m_name(name){
	}
	void who(void){
		cout << m_name << endl;
	}
	string m_name;
	static int s_data;
	static int s_add(int a,int b){
		return a+b;
	}
};
int Student::s_data = 100;
int main(void)
{
	//pwho是成员函数指针
	void (Student::*pwho)(void) = &Student::who;
	Student s1("张飞");
	Student s2("赵云");
	(s1.*pwho)();
	Student *ps = &s2;
	(ps->*pwho)();
	//静态成员指针,在使用定义和普通指针没有区别
	int  *pdata = &Student::s_data;
	cout << *pdata << endl;
	int (*padd)(int,int) = Student::s_add;
	cout << padd(12,13) << endl;
	
	return 0;
}





