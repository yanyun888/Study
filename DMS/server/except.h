/* File Name: except.h
** Author: 
** Version: 
** Created Time: 15/09/24-09:59  */
 
//异常类 
#ifndef _EXCEPT_H
#define _EXCEPT_H

#include <string>
using namespace std;

class ServerException:public exception{
public:
	ServerException(void):m_msg("客户机异常！"){}
	ServerException(string const& msg):m_msg("客户机异样:"){
		m_msg += msg;
		m_msg += '!';
	}
	//对虚函数进行覆盖
	~ServerException(void)throw(){}
	char const* what(void) const throw(){
		return m_msg.c_str();
	}
private:
	string m_msg;
};
//数据库异常
class DBException:public ServerException{
public:
	DBException(void):ServerException("备份错误"){}
	DBException(string const& msg):ServerException(msg){}
	//没有类类型的成员变量，这个类的析构函数已经没有了。
};
//线程异常
class ThreadException:public ServerException{
public:
	ThreadException(void):ServerException("存储错误"){}
	ThreadException(string const& msg):ServerException(msg){}
};
//网络异常
class SocketException:public ServerException{
public:
	SocketException(void):ServerException("网络错误"){}
	SocketException(string const& msg):ServerException(msg){}
};


#endif //_EXCEPT_H
