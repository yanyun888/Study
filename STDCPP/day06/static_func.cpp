#include <iostream>
using namespace std;

class A{
public:
	//普通函数访问静态成员变量
	void foo(void){
		cout << "foo" << endl;
		cout << s_data << endl;
	}
	static void set(int data){
		cout << "set" << endl;
		//静态函数不能访问非静态成员变量
		//cout << m_data << endl;//error
		s_data = data;
	}
	static int get(void){
		return s_data;
	}
private:
	static int s_data;	
	int m_data;
};
int A::s_data = 10;
int main(void)
{
	A a1;
	cout << a1.get() << endl;
	A a2;
	a2.set(20);
	cout << a1.get() << endl;
	a1.foo();
}

