/* File Name: 05error.cpp
** Author: 
** Version: 
** Created Time: 15/09/16-15:15  */
 
 
#include <iostream>
#include <csetjmp>
#include <cstdio>
using namespace std;

jmp_buf g_env;

class A{
public:
	A(void){
		cout << "A构造" << endl;
	}
	~A(void){
		cout << "A析构" << endl;
	}
};

int func3(void){
	A a;
	FILE * fp=fopen("none.txt","r");
	if(!fp){
		longjmp(g_env,-1);
	}
	fclose(fp);
	return 0;
}
int func2(void){
	A a;
	func3();
		return -1;
	return 0;
}

int func1(void){
	A a;
	func2();
	return 0;
}


int main(){
	if(setjmp(g_env)==-1){
		cout << "文件打开失败" << endl;
		return -1;
	}
	func1();

	return 0;
}

