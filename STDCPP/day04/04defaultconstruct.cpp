/* File Name: 04defaultconstruct.cpp
** Author: 
** Version: 
** Created Time: 15/09/08-11:31  */
 
 
#include <iostream>
using namespace std;

class Student{


public:
	Student(int data=0){
		m_data = data;
	}

private:
	int m_data;


};



int main(){

	Student *ps = new Student[3];
	/*{
		Student(10),
		Student(20),
		Student(30)
	}
	*/

	return 0;
}
