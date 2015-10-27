/* File Name: 04exception.cpp
** Author: 
** Version: 
** Created Time: 15/09/16-15:01  */
 
 
#include <iostream>
//#include <cfcntl>
#include <cstdio>
using namespace std;


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
		cout << "文件打开失败" <<endl;
		return -1;
	}
	fclose(fp);
	return 0;
}
int func2(void){
	A a;
	if(func3()==-1){
		return -1;
	}
	return 0;
}

int func1(void){
	A a;
	if(func2() == -1)
		return -1;
	return 0;
}


int main(){
	func1();

	return 0;
}

