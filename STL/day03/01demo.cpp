
#include <iostream>
using namespace std;

template<typename T,size_t S>
class Array{
public:
	T& operator[](size_t i){
		return m_array[i];
	}
	T const& operator[](size_t i)const{
		return  const_cast<Array&>(*this)[i];
	}
	size_t size(void) const{
		return sizeof(m_array) / sizeof(m_array[0]);
	}
	friend ostream& operator<< (ostream& os,Array const& array){
		for(size_t i=0;  i< array.size(); ++i)
			os << '(' <<array[i] <<')';
		return os;
	}
private:
	T m_array[S];
};
int main(void){
	Array<int,5> a1;
	for(int i=0 ;  i<a1.size() ; ++i)
		a1[i] = (i+1) * 10;
	cout << a1 << endl;

}



