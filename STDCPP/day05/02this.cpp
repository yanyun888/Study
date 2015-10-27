/* File Name: 02this.cpp
** Author: 
** Version: 
** Created Time: 15/09/09-11:16  */
 
 
#include <iostream>
using namespace std;

class User{



public:
	User(const string& name="", int age = 0):m_name(name),m_age(age){

	}
	void print(void){
		cout << this->m_name <<","<<this->m_age <<endl;
	}

private:
	string m_name;
	int m_age;

};


int main(){
	User u1("张飞",25), u2("赵云",26);
	u1.print();
	u2.print();




	return 0;
}
