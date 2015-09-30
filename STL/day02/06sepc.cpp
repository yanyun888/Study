/*File Name: 06sepc.cpp
**Author: 
**Version: 
**Created Time: 15/09/30-14:21  */
 
#include <cstring>
#include <iostream>
using namespace std;

template<typename T>
T max(T x,T y){
	return x < y ? y : x ;
}
char* max(char* x,char* y){
	return strcmp(x,y) < 0 ? x : y;
}
template<typename T>
class Comparator{
public:
	Comparator(T x,T y):m_x(x),m_y(y){}
	Comparator max(void) const{
		return m_x < m_y ? m_y : m_x;
	}
private:
	T m_x;
	T m_y;
};
/*
//全类特化
template<>
class Comparator<char*>{
public:
	Comparator (char* x,char* y):m_x(x),m_y(y){}
	char* max(void){
		return strcmp(m_x,m_y) < 0 ? m_x : m_y;
	}
private:
	char* m_x;
	char* m_y;
};
*/
//成员特化
template<>
char* Comparator<char*>::max(void) const{
	return strcmp(m_x,m_y)<0 ? m_x:m_y; 
}


int main(){
	int a = 123,b=456;
	cout << ::max(a,b) << endl;
	double c =1.23,d = 4.56;
	cout << ::max(c,d) << endl;
	string e = "hello",f = "world";
	cout << ::max(e,f) << endl;
	char g[] = "hello",h[]="world"; //写max
	cout << ::max(g,h) << endl;
	cout << ::max(string(g),string(h))<< endl;

	return 0;
}


