/* File Name: 06constOver.cpp
** Author: 
** Version: 
** Created Time: 15/09/09-15:26  */
 
 
#include <iostream>
using namespace std;

class B{

public:
	void hum(void) const{
		cout << "hum的常函数" << endl;
	}
	void hum(void){
		cout << "hum的非常函数" << endl;
	}

};



int main(){

	B b1;
	const B b2 = B;
	b1.hum();
	b2.hum();

	return 0;
}


