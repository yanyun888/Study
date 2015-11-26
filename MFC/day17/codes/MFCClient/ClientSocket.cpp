// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "MFCClient.h"
#include "ClientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions
BOOL CClientSocket::InitClient(char *IP,UINT nPort)
{
    if (!Create())
    {
		return FALSE;
    }
	return Connect(IP,nPort);
}
BOOL CClientSocket::SendData(BYTE* pData,long nLen)
{
	BYTE* pTmpData=pData;
	long nLeft=nLen;
	while(nLeft>0)
	{
		int nSend=Send(pTmpData,nLeft);
		if (SOCKET_ERROR==nSend)
		{
			return FALSE;
		}
		nLeft-=nSend;
		pTmpData+=nSend;
	}
	return TRUE;
}
typedef struct _tagHeader
{
	char szName[256];//文件名称
	long nLen;//文件长度
}HEADER,*LPHEADER;
BOOL CClientSocket::SendFile(CString strPath)
{
	//发送文件

	// 0 打开文件，获取文件信息和数据
    CFile file;
	file.Open(strPath,CFile::modeRead);
	DWORD nLen=file.GetLength();
    BYTE* pData=(BYTE*)malloc(nLen);
	file.Read(pData,nLen);
	// 1 首先发送文件信息
    HEADER header={0};
	header.nLen=nLen;
	strcpy(header.szName,file.GetFileName());
    SendData((BYTE*)&header,sizeof(header));
	// 2 然后发送文件数据
	SendData(pData,nLen);
	file.Close();
	free(pData);
	// 关闭
	Close();
	return TRUE;
}