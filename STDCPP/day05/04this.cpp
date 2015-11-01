/* File Name: 04this.cpp
** Author: 
** Version: 
** Created Time: 15/09/09-14:08  */
 
 
#include <iostream>
using namespace std;

class Student;
class Teacher{
public:
	void educate(Student* student);
	void reply(const string& answer){
		m_answer = answer;
	}
private:
	string m_answer;
};
class Student{
public:
	void ask(const string& question,Teacher* teacher){
		cout << "问题：" << question <<endl;
		teacher->reply("this指针就是。");	
	}
};
void Teacher::educate(Student* student){
	student->ask("什么是this指针",this);
	cout << "回答：" << m_answer << endl;
}



int main(){
	Teacher t;
	Student s;
	t.educate(&s);


	return 0;
}
