/*File Name: 01funcTemplate.cpp
**Author: 
**Version: 
**Created Time: 15/10/08-10:55  */
 
 
#include <iostream>
using namespace std;

int square(int x){
	return x*x;
}

template<int x>
int square(void){
	return x*x;
}

/*模板的非类型参数不能选择浮点类型：float/double
template<int x>
int square(void){
	return x*x;
}
*/

/*
   也不能选择类类型
template<string s>
void foo(void){
	cout << s << endl;
}
*/

template<char const* p>
void bar(void){
	cout << p << endl;
}

char g[]="string";
//作为接受字符指针形式字符串非类型参数的模板实参，只能选择具有外部链接特性的全局自负数据。
int main(void){
	cout << square(10) << endl;
	cout << square<10>() << endl;
//	bar<"string">();
	bar<g>();
	return 0;
}

