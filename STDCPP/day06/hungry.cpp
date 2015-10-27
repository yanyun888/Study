#include <iostream>
using namespace std;
class Singleton{
public:
	//提供静态私有的对象访问接口
	static Singleton& getInstance(void){
		return s_instance;
	}
private:
	Singleton(void){
		cout << "Singleton::Singleton()" << endl;
	}
	Singleton(const Singleton&){}
	//私有拷贝赋值，防止自己复制自己
	Singleton& operator=(const Singleton&);
	static Singleton s_instance;
	//静态成员变量，会在类声明的时候构造一份	
};
Singleton Singleton::s_instance;
int main(void)
{
	cout << "main()" << endl;
	//外部只能获取对象的别名
	Singleton& s1 = Singleton::getInstance();
	Singleton& s2 = Singleton::getInstance();
	Singleton& s3 = Singleton::getInstance();
	cout << &s1 << ',' << &s2 << ',' << &s3 <<endl;
	//Singleton s4;
	//Singleton s5(s1);
	//s1 = s2;
	return 0;
}



