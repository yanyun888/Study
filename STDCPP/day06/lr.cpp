#include <iostream>
using namespace std;
int g = 0;
int foo(void){return g;}
int &bar(void){return g;}
void func(int &i){
	cout << "func(int&)" << endl;
}
void func(const int &i){
	cout << "func(const int&)" << endl;
}
int main(void)
{
	int i;
	int *p = &i;
	i = 10;
	//p = &10;
	//10++;
	//++foo();
	bar()++;
	bar()=100;
	int a =3 ,b =5;
	const int c = a+b;
	//(a+b) = 10;
	(a += b) = 10;
	++a = 100;
	++++a;
	//a++ = 200;
	char r = 0;
	//int &rr = 10;
	const int& rr = r;
	func(r);
}




