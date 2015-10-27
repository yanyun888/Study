/* File Name: 51initOrder.cpp
** Author: 
** Version: 
** Created Time: 15/09/09-10:00  */
 
 
#include <iostream>
using namespace std;

class Message{
public:
	Message(const string& str):m_str(str),m_len(m_str.length()){
//这里如果使用m_str作为计算字符串的长度，则会留下拉圾值，
	}
	void show(void){
		cout << m_str << endl;
	}
	size_t getSize(void){
		return m_len;
	}


private:
	size_t m_len;
	string m_str;
};



int main(){

	Message m("Hello");
	m.show();
	cout << m.getSize()<< endl;

	return 0;
}

