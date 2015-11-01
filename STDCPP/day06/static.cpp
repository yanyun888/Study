#include <iostream>
using namespace std;
class A{
public:
	int m_data;
/*private:*///受到访控属性约束
	static int s_data;
};
int A::s_data = 10;//定义并初始化
int main(void)
{
	A a;
	cout << sizeof(a) << endl;
	cout << A::s_data << endl;//通过类调用
	cout << a.s_data << endl;//通过对象调用
	A a2;
	a2.s_data = 20;
	cout << a.s_data << endl;//多个对象之间共享
	return 0;
}
