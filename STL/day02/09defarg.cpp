/*File Name: 09defarg.cpp
**Author: 
**Version: 
**Created Time: 15/09/30-16:14  */
 
 
#include <iostream>
#include <typeinfo>
using namespace std;

template<typename A=int,typename B=double,typename C=string>
class X{
public:
	static void print(void){
		cout << typeid(A).name()<<','
			<< typeid(B).name()<<','
			<<typeid(C).name()<< endl;
	}

};



int main(){

	X<int,double,string>::print();
	X<int,double>::print();

	return 0;
}
