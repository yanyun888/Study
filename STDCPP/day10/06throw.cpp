/* File Name: 06throw.cpp
** Author: 
** Version: 
** Created Time: 15/09/16-16:14  */
 
 
#include <iostream>
#include <csetjmp>
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
class FileError{
public:
	FileError(){}
	FileError(const string& file,int line):m_file(file),m_line(line){
		cout<<"出错位置" << m_file <<','<<m_line<<endl;
	}
private:
	string m_file;
	int m_line;
};
int func3(void){
	A a;
	FILE * fp=fopen("none.txt","r");
	if(!fp){
		throw FileError(__FILE__,__LINE__);
		throw -1;
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
	/*
	if(setjmp(g_env)==-1){
		cout << "文件打开失败" << endl;
		return -1;
	}
	*/

	try{
		func1();
	}
	catch(int ex){
	//	return -1;
		if(ex == -1){
			cout << "文件打开失败" <<endl;
		}
		return -1;

	}
	catch(FileError ex){
		cout << "打开文件失败!" << endl;
		return -1;
	}


	return 0;
}


