#include <iostream>
#include <cstdio>
using namespace std;
class Student{
public:
	Student(const string& name = ""):m_name(name){
	}
	string m_name;
};
int main(void)
{
	//pname即是成员指针
	string Student::* pname = &Student::m_name;
//	printf("%p\n",pname);

	Student s1("张飞");
	Student s2("赵云");
	cout << s1.*pname << endl;
	cout << s2.*pname << endl;
	Student *ps = &s1;
	cout << ps->*pname << endl;
}





