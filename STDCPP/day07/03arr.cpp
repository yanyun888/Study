/* File Name: 03arr.cpp
** Author: 
** Version: 
** Created Time: 15/09/11-14:47  */
 
 
#include <iostream>
using namespace std;

class Array{
public:
	Array(size_t size):m_size(size),m_data(new int[size]){
	}
	~Array(void){
		if(m_data){
			delete[] m_data;//这里为什么不加[]
			m_data=NULL;//这样的是可以成功判断的么？
		}
	}
	int& operator[](size_t i){
		return m_data[i];
	}
	int operator[](size_t i) const{//针对于常对象进行重载,基本类型返回匿名变量是右值
//		return m_data[i];
		return const_cast<Array&>(*this)[i];//直接复用非常函数的版本。
	}

private:
	int* m_data;
	size_t m_size;
};


int main(){
	Array a(10);
	cout << a[0] << ',' << a[4] <<endl;

	a[0] = 13;
	a[4] = 15;
	
	cout << a[0] << ',' << a[4] <<endl;
	
	const Array& r = a;
	cout << r[0] << ',' << r[4] <<endl;//常对象只能调用常函数。
	return 0;

}

