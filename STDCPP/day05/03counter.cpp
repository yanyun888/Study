/* File Name: 03counter.cpp
** Author: 
** Version: 
** Created Time: 15/09/09-11:43  */
 
 
#include <iostream>
using namespace std;

class Counter{

public:
	Counter(int data = 0):m_data(data){
	}
	/*
	void add(void){
		++m_data;
	}
	*/
	void destroy(void){
		delete this; // 自销毁
	}
	Counter& add(void){
		++m_data;
		return *this;//返回自引用，实现函数的级联调用
	}
	int getData(void){
		return m_data;
	}
private:
	int m_data;
};


int main(){
	Counter cn;
	cn.add().add();
	cn.add();
	cout << cn.getData()<<endl;
	Counter* pcn = new Counter;
	pcn->destroy();



	return 0;
}


