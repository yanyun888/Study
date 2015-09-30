/*File Name: 02overload.cpp
**Author: 
**Version: 
**Created Time: 15/09/30-09:40  */
 
 
#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <cstring>
using namespace std;

//两个任意类型值的最大值
template<typename T>
T const& max(T const& x,T const& y){
	cout << "<1" << typeid(x).name() << ">" << flush;
	return x < y ? y : x;
}

//两个任意类型指针所指向目标的最大值
template<typename T>
T* const& max(T* const& x,T* const& y){
	cout << "<2" << typeid(x).name() << ">" << flush;
	return *x < *y ? y : x;
}
//两个C风格字符串的最大值
char const* const& max(char const* const& x, char const* const& y){
	cout << "<3" << typeid(x).name() << ">" << flush;
	return strcmp(x,y) < 0 ? y:x;
}

/*
char const* max(char const* x, char const* y){
	cout << "<3" << typeid(x).name() << ">" << flush;

	return strcmp(x,y) < 0 ? y:x;
	//不加引用可能会有警告：返回一个局部变量的引用
}
*/
template<typename T>
T const& max(T const& x,T const& y,T const& z){
	cout << "<4"<< typeid(x).name()<< ">" << flush;
	return ::max(::max(x,y),z);
}

int main(void){
	int a=123,b=456;
	cout << ::max(a,b) << endl;
	cout << *::max(&a,&b) << endl;
	char const* c = "ab";
	char const* d = "abc";
	cout << ::max(c,d) << endl;
	cout << ::max<>(c,d) << endl; //加尖括号会忽略普通函数，选择模板函数

	//函数模板重载解析在类型约束性强者优先的原则下还必须满足调用参数的一致性
	cout << ::max<char const*>(c,d) << endl; //注意会调用第一种
	int e = 789;
	cout << ::max(a,b,e) << endl;
	char const* f = "abcd";
	cout << ::max(c,d,f) << endl;
	//选择何种类型是在第二次编译的时候做的，但是选择的范围是在第一次编译时确定的。
								
	return 0;
}

