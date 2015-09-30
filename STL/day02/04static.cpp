/*File Name: 04static.cpp
**Author: 
**Version: 
**Created Time: 15/09/30-11:45  */
 
 
#include <iostream>
using namespace std;

template<typename T>
class A{
public:

	static int s_x; //只是声明，没有定义
private:

};
template<typename T>
int A<T>::s_x;

int main(){
	A<int> a,b;
	A<double> c,d;
	cout << &a.s_x << ' ' << &b.s_x << endl;
	cout << &c.s_x << ' ' << &d.s_x << endl;


	return 0;
}
