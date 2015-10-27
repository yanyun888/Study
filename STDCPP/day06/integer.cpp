#include <iostream>
using namespace std;
class Integer{
public:
	Integer(int data = 0):m_data(new int(data)){
		cout << "Integer的构造函数" << endl;
	}/*浅拷贝
	Integer(const Integer& that):
				m_data(that.m_data){
		cout << "拷贝构造函数" << endl;			
	}*/
	/*深拷贝*/
	Integer(const Integer& that):
			m_data(new int(*that.m_data)){
		cout << "拷贝构造函数" << endl;		
	}
	/*缺省的拷贝赋值，浅拷贝
	Integer& operator=(const Integer& that){
		m_data = that.m_data;
	}*/
	/*深拷贝赋值*/
	Integer& operator=(const Integer& that){
		if(&that != this){//防止自拷贝
			delete m_data;//释放旧资源
			//分配新资源,拷贝新数据
			m_data = new int(*that.m_data);
		}
		return *this;//返回自引用
	}

	~Integer(void){
		cout << "Integer的析构函数" << endl;
		if(m_data){
			cout << "this->m_data:" << 
					this->m_data << endl;
			delete m_data;
			m_data = NULL;
		}
	}
	int get(void)const{
		return *m_data;
	}
private:
	int *m_data;
};
int main(void)
{
	Integer i(100);
	Integer j(i);//拷贝构造
	cout << j.get() << endl;

	Integer i2(200);
 	i2 = j;//拷贝赋值 i2.operator=(i);
	cout << i2.get() << endl;

	return 0;
}


