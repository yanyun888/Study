/*File Name: 03classtemplate.cpp
**Author: 
**Version: 
**Created Time: 15/09/30-11:09  */
 
 
#include <iostream>
using namespace std;

template<typename T>
class Comparator{
public:
	Comparator(T x,T y):m_x(x),m_y(y){}
	Comparator(Comparator<T> const& that):
		m_x(that.m_x),m_y(that.m_y){}
	Comparator<T>& operator=(Comparator<T> const& rhs){
		if(&rhs != this){
			m_x = rhs.m_x;
			m_y = rhs.m_y;
		}
	}
	T max(void) const{
		return m_x < m_y ? m_y : m_x;
	}
	T min(void) const {
		return m_x < m_y ? m_x : m_y;
	}
	friend ostream& operator<<(ostream& os,Comparator<T> const& c){
		return os<<c.m_x<<','<<c.m_y;
	}
private:
	T m_x;
	T m_y;
};



int main(void){
	Comparator<int> ci (123,456);
	cout << ci.max() << endl;
	return 0;
}

