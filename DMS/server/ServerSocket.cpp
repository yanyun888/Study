/*File Name: ServerSocket.h
**Author: 
**Version: 
**Created Time: 15/09/28-15:53  */

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <cstring>
#include <iostream>
using namespace std;
#include "ServerSocket.h"
#include "ClientThread.h"


ServerSocket::ServerSocket(short port,string const& ip /* ="" */)
		throw (SocketException){
	cout << "初始化服务器开始..." << endl;
	if((m_sockfd = socket(AF_INET,SOCK_STREAM,0) ) == -1)
		throw SocketException(strerror(errno));
	int on = 1;
	if((setsockopt (m_sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on) )) ==-1){
		close(m_sockfd);
		throw SocketException ( strerror(errno));
	}
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = ip.empty() ? INADDR_ANY : inet_addr(ip.c_str());
	if(bind(m_sockfd,(sockaddr*)&addr,sizeof(addr)) == -1){
		close(m_sockfd);
		throw SocketException(strerror(errno));
	}
	if(listen(m_sockfd,1024) == -1){
		close(m_sockfd);
		throw SocketException(strerror(errno));
	}
	cout << "初始化服务器完成。" << endl;
}
void ServerSocket::acceptClient(void) throw (SocketException){
	for(;;){
		cout << "等待客户机连接..." << endl;
		sockaddr_in addrcli;
		socklen_t addrlen = sizeof(addrcli);
		int connfd = accept(m_sockfd,(sockaddr*)&addrcli,&addrlen);
		if(connfd == -1){
			close(m_sockfd);
			throw SocketException(strerror(errno));
		}
		(new ClientThread(connfd))->start();
	}

}








