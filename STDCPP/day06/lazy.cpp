#include <iostream>
using namespace std;
class Singleton{
public:
	//提供静态私有的对象访问接口
	static Singleton& getInstance(void){
		if(s_instance == NULL)//保证只new一次
			s_instance = new Singleton;
		++s_counter;
		return *s_instance;
	}
	void releaseInstance(void){
		/*当只有一个对象别名时才delete*/
		if(s_counter && --s_counter==0){
			delete this;//自销毁
		}
	}
private:
	Singleton(void){
		cout << "Singleton::Singleton()" << endl;
	}
	~Singleton(void){
		cout << "~Singleton::Singleton()" << endl;
		s_instance = NULL;
	}
	Singleton(const Singleton&){}
	//私有拷贝赋值，防止自己复制自己
	Singleton& operator=(const Singleton&);
	static Singleton* s_instance;
	static size_t s_counter;//计数
};
Singleton* Singleton::s_instance=NULL;
size_t Singleton::s_counter = 0;

int main(void)
{
	cout << "main()" << endl;
	//外部只能获取对象的别名
	Singleton& s1 = Singleton::getInstance();
	Singleton& s2 = Singleton::getInstance();
	Singleton& s3 = Singleton::getInstance();
	cout << &s1 << ',' << &s2 << ',' << &s3 <<endl;
	s1.releaseInstance();
	s2.releaseInstance();
	s3.releaseInstance();
	return 0;
}





