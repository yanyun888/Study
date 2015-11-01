/* File Name: 02inheritance.cpp
** Author: 
** Version: 
** Created Time: 15/09/14-10:03  */
 
 
#include <iostream>
using namespace std;

class Human{
public:
	Human(const string& name,int age,int id=100):m_name(name),m_age(age),m_id(id){}
	void eat(const string& food)const{
		cout << "我在吃" << food << endl;
	}
	void sleep(int dur)const{
		cout << "我睡了" << dur << "小时" <<endl;
	}
	int const& getid(void){
		return m_id;
	}
protected:
	string m_name;
	int m_age;
private:
	int m_id;
};

class Student:public Human{//派生子类
public:
	Student(const string& name,int age,int no):Human(name,age),m_no(no){}
	void who(void) const{
		cout << "我叫" << m_name <<"，今年" << m_age <<"岁，我的学号是" << m_no <<endl;
	}
	void learn(const string& course){
		cout << "我在学" << course << endl;
	}
private:
	int m_no;

};

class Teacher:public Human{
public:
	Teacher(const string& name,int age,double salary):Human(name,age),m_salary(salary){}
	void who(void) const{
		cout << "我叫" << m_name <<"，今年" << m_age <<"岁，我的工资" << m_salary <<endl;
	}
	void teach(const string& course)const{
		cout << "我在教" << course << endl;
	}
private:
	double m_salary;
};


int main(){

	Student s("David",15,10050);
	s.who();
	s.sleep(5);
	Teacher t("Amanda",35,2540.5);
	t.who();

	Human* ph = &s;
	ph->eat("melon");
	ph->sleep(5);

	Student* ps = static_cast<Student*>(ph);//向下造型 需要显式转换
	ps->who();
	
	Human h("Kate",35);
	Teacher &rt = static_cast<Teacher&>(h);
	rt.who();
	cout << rt.getid() << endl;

	return 0;
}

