/* File Name: 50initTable.cpp
** Author: 
** Version: 
** Created Time: 15/09/09-09:32  */
 
 
#include <iostream>
using namespace std;

class Circle{

public:
	//Circle(double pi,double& r):m_pi(pi),m_r(r){
	Circle(double pi,double& r):m_r(r){
		cout<<"Circle的构造函数"<<endl;
		m_pi = pi;
//		m_r = 1;
	}
	double perimeter(void){
		return 2*m_pi*m_r;
	}
	double getR(void){
		return m_r;
	}
	double getPI(void){
		return m_pi;
	}



private:
	double /* const */ m_pi;
	double& m_r;

};


int main(){
	double r = 10;
	Circle cir(3.14,r);
	cout << "周长："<<cir.perimeter()<<endl;
	cout << "r= " << cir.getR() << endl;
	cout << "PI=" << cir.getPI() << endl;


	return 0;
}

