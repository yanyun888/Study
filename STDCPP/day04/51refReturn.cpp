/* File Name: 51refReturn.cpp
 ** Author: 
 ** Version: 
 ** Created Time: 15/09/08-18:39  */


#include <iostream>
using namespace std;
int g = 123;
struct Dummy {
	int m;
	int& foo (void) {
		return g; }
	int& bar (void) {
		static int s = 456;
		return s; 
	}
	int& hum (void) {
		return m; 
	}
	Dummy& up (void) {
		++m;
		return *this; 
	}
};
int& square (int x) {

	int* y = new int;
	*y = x * x;
	return *y;
}
int const& max (int const& a, int const& b){
	//这里的int const& 与  const int& 是否一致
	return a > b ? a : b;
}
int& foo (void)
{

	int n = 123;
	return n;
}
int main(int argc, const char * argv[])
{

	Dummy dummy = {
		789};
	int& rg = dummy.foo ();
	std::cout << "rg = " << rg << std::endl;
	int& rs = dummy.bar ();
	std::cout << "rs = " << rs << std::endl;
	int& rm = dummy.hum ();
	std::cout << "rm = " << rm << std::endl;
	dummy.up().up().up();
	std::cout << "rm = " << rm << std::endl;
	int& y = square(16);
	std::cout << y << std::endl; // 256
	delete &y;
	int a = 123, b = 456;
	std::cout << &a << ' ' << &b << std::endl;
	int const& c = max (a, b);
	std::cout << &c << " : " << c << std::endl;
	int &z = foo();
	std::cout << "z = " << z << std::endl;
	return 0;
}


