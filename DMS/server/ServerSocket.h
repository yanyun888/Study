/*File Name: ServerSocket.h
**Author: 
**Version: 
**Created Time: 15/09/28-15:53  */
 
//生命一个服务器套接字类 
#ifndef _SERVERSOCKET_H
#define _SERVERSOCKET_H

#include "except.h"
//服务器套接字

class ServerSocket{
public:
	ServerSocket(short port,string const& ip = "")
		throw (SocketException);
	void acceptClient(void) throw (SocketException);

private:
	int m_sockfd; //监听套接字


};





#endif //_SERVERSOCKET_H
