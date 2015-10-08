/*File Name: 07emit.cpp
**Author: 
**Version: 
**Created Time: 15/10/08-15:07  */
 
 
#include <iostream>
using namespace std;

template<typename T>
void foo(void){
	T t = T (); //零初始化
// int t = int ();
// string s = string ();
// Integer s = Integer ();
	cout << t << endl;
}

template<typename T>
class A{
public:
private:
};



class Integer{
public:
	Integer(int data = 0) : m_data(data){}
	operator int& (void){
		return m_data;
	}
	operator int const& (void) const{
	//	return 
		return m_data;
	}

private:
	int m_data;
};


int main(){
	return 0;
}


