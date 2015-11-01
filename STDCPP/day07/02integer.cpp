/* File Name: 02integer.cpp
** Author: 
** Version: 
** Created Time: 15/09/11-11:19  */
 
 
#include <iostream>
using namespace std;

class Integer{
public:
	Integer(int i=0):m_i(i){}
	void print(void)const{
		cout << m_i <<endl;
	}
	const Integer operator-(void) const{
		return Integer(-m_i);
	}
	const Integer operator+(const Integer l){
		return Integer(this->m_i+l.m_i);
	}
	Integer& operator++(void){//前++
		++m_i;
		return *this;
	}
	const Integer operator++(int){//后++
		Integer old = *this;
		++*this;
		return old;
	}
	friend Integer& operator--(Integer& i);
	friend const Integer operator~(const Integer& i){
		return Integer(i.m_i*i.m_i);//这里的是局部变量，不能返回其引用
	}
private:
	int m_i;
};

Integer& operator--(Integer& i){
	--i.m_i;
	return i;
}
const Integer operator--(Integer& i,int){
	Integer old = i;
	--i;
	return old;
}

int main(){
	Integer i(100);
	Integer j=-i;
	j.print();
	Integer k=~i;
	k.print();
	++k;
	k.print();
	Integer m;
	m = k + i;
	cout << "m" << endl;
	m.print();
	

	return 0;
}

