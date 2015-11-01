/* File Name: 06reffunc.cpp
** Author: 
** Version: 
** Created Time: 15/09/06-14:35  */
 
 
#include <iostream>
#include <cstdio>
using namespace std;

void swap1(int x,int y){
	x=x^y;
	y=x^y;
	x=x^y;
}

void swap2(int* x,int* y){
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void swap3(int& x,int& y){
	x=x xor y;
	y=x xor y;
	x=x xor y;
	cout << "&x=" << &x <<",&y="<<&y<<endl;
}

void swap4(const char* x,const char* y){
	const char* z = x;
	x = y;
	y = z;
}
void swap5(const char** x,const char** y){
	const char* z = *x;
	*x = *y;
	*y = z;
}
void swap6(const char* &x,const char* &y){
	const char* z = x;
	x = y;
	y = z;
}

int main(){

	int num1=3,num2=5;
	//swap1(num1,num2);
	//swap2(&num1,&num2);
	swap3(num1,num2);
	cout << num1 <<','<<num2<<endl;
	cout << "&num1=" << &num1 <<",&num2="<<&num2<<endl;

	const char *s1 = "hello";//常量指针，指向常量的指针
	const char *s2 = "world";//
	//swap4(s1,s2);
	//swap5(&s1,&s2);
	swap6(s1,s2);
	cout<<s1<<' '<<s2<<' '<<endl;

	int a = 1;
	printf("%d\n",sizeof( (a>5)?4:8.0 ));


	return 0;
}




