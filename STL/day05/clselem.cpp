#include <iostream>
#include <vector>
using namespace std;
class A {
public:
	A (void) {
		cout << "缺省构造：" << this << endl;
	}
	A (A const& a) {
		cout << "拷贝构造：" << &a << "->" << this
			<< endl;
	}
	A& operator= (A const& a) {
		cout << "拷贝赋值：" << &a << "->" << this
			<< endl;
	}
	~A (void) {
		cout << "析构函数：" << this << endl;
	}
};
int main (void) {
	cout << "---- 1 ----" << endl;
	vector<A> va (3);
	cout << "---- 2 ----" << endl;
	va.push_back (A ());
	cout << "---- 3 ----" << endl;
	va.erase (va.begin ());
	cout << "---- X ----" << endl;
	return 0;
}
