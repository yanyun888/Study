// ServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "MFCServer.h"
#include "ServerSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CServerSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CServerSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CServerSocket member functions
BOOL CServerSocket::InitServer(UINT nPort)
{
	//创建、绑定
	if (!Create(nPort))
	{
		return FALSE;
	}
	//监听
	return Listen();
}

typedef struct _tagHeader
{
	char szName[256];//文件名称
	long nLen;//文件长度
}HEADER,*LPHEADER;
void CServerSocket::OnAccept(int nErrorCode) 
{
	// 接收客户端连接
	CSocket client;
	Accept(client);
	// 通信(接收文件)
    // 1 首先接收文件信息(包括文件名和长度)
    HEADER header={0};
    RecvData(client,(BYTE*)&header,sizeof(header));
	// 2 然后接收文件数据
    CString strPath="c:/";
	strPath+=header.szName;//文件路径
	BYTE* pData=(BYTE*)malloc(header.nLen);
	RecvData(client,pData,header.nLen);
	//3 保存文件
	CFile file;
	file.Open(strPath,
		CFile::modeCreate|CFile::modeWrite);
	file.Write(pData,header.nLen);
	file.Close();
	free(pData);
	
	// 关闭
	client.Close();

	CAsyncSocket::OnAccept(nErrorCode);
}

BOOL CServerSocket::RecvData(CSocket& client,
					   BYTE* pData,long nLen)
{	BYTE* pTmpData=pData;
	//剩余的还没有接收的数据的长度
	long nLeft=nLen;
	while (nLeft>0)
	{
		int nRecv=client.Receive(pTmpData,nLeft);
        if (SOCKET_ERROR==nRecv)
        {
			return FALSE;
        }
		pTmpData+=nRecv;
        nLeft-= nRecv;
	}
	return TRUE;

}