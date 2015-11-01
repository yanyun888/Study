/* File Name: 05op_ptr.cpp
** Author: 
** Version: 
** Created Time: 15/09/11-16:11  */
 
 
#include <iostream>
using namespace std;
//智能指针
#include <memory>

class A{
public:
	A(const string& str = ""):m_str(str){
		cout << "A构造" << endl;
	}
	~A(void){
		cout << "A析构"<<endl;
	}
	string m_str;	

private:


};

class PA{

public:
	PA(A* pa=NULL):m_pa(pa){}
	~PA(void){
		if(m_pa){
			delete m_pa;
			m_pa = NULL;
		}
	}

	A& operator*(void) const{
		return *m_pa;
	}
	A* operator->(void) const{
		return m_pa;
	}
private:
	A* m_pa;
};

int main(){
#if 0
	PA pa(new A("hello world"));
	cout << pa->m_str << endl;
	cout << (*pa).m_str << endl;
#endif
	//标准库实现的智能指针
	auto_ptr<A>pa(new A);
	pa->m_str = "hello world";
	cout << pa->m_str << endl;
	cout << (*pa).m_str << endl;

	return 0;
}


