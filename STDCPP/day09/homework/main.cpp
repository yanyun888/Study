/* File Name: main.cpp
** Author: 
** Version: 
** Created Time: 15/09/15-19:03  */
 
 
#include <iostream>
#include "employee.h"
using namespace std;

int main(){

	Technican t1("samson",5,TECHNICAN);
	//Employee& e1=t1;
	t1.show();
	cout << "t1 bonus="<<t1.bonus()<<endl;
	Manager m1("mark",8,MANAGER);
	cout << "m1 bonus="<<m1.bonus()<<endl;
	//t1.setHour();
	//cout << t1.bonus()<<endl;
	Techmanager tm2("hello",9,TECHMANAGER);
	cout << "tm2 bonus=" << tm2.bonus()<<endl;
	Salesmanager sm1("tttys",10,SALESMANAGER);
	cout << "sm1 bonus=" << sm1.bonus()<<endl;
	cout <<"-----------------" <<endl;
	GRADE g=TECHNICAN;
	cout << g <<endl;
	return 0;
}

