/*File Name: 06tmv.cpp
**Author: 
**Version: 
**Created Time: 15/10/08-14:16  */
 
 
#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T>
class Array{
public:
	void push_back(T const& data){
		cout << "压入尾元素" << endl;
	}
	void push_front(T const& data){
		cout << "压入首元素" << endl;
	}
	void pop_back(void){
		cout << "弹出尾元素" << endl;
	}
	void pop_front(void){
		cout << "弹出首元素" << endl;
	}

private:
	T m_array[256];
};

template<typename T>
class Stack{
public:
	Stack (void){
	//补充一个缺省构造
	}
	template<typename E>
	Stack (Stack<E> const& that) {
		cout << "从"<<typeid(E).name()<<"类型的堆栈转换为"
			<< typeid(T).name() << "类型的堆栈" << endl;
	}
	void push(T const& data){
		m_container.push_back(data);
	}
	void pop(void){
		m_container.pop_back();
	}
 //模板形式的成员类型
	template<typename F>
	class Dummy{
	public:
		Dummy(F const& f) : m_f (f){}
		F m_f;
	};
	/*
	template<typename>
	 
	 */



private:
	Array<T> m_container; //模板形式的成员变量
};
//适配器模式(设计模式)







int main(void){

	Stack <int> si;
	si.push (100);
	si.push (100);
	si.pop ();
	si.pop ();
	Stack <double> sd;

	sd = si; //两种不同类型之间的堆栈进行转换

	return 0;
}


