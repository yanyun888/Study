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
	//��������
	if (!Create(nPort))
	{
		return FALSE;
	}
	//����
	return Listen();
}

typedef struct _tagHeader
{
	char szName[256];//�ļ�����
	long nLen;//�ļ�����
}HEADER,*LPHEADER;
void CServerSocket::OnAccept(int nErrorCode) 
{
	// ���տͻ�������
	CSocket client;
	Accept(client);
	// ͨ��(�����ļ�)
    // 1 ���Ƚ����ļ���Ϣ(�����ļ����ͳ���)
    HEADER header={0};
    RecvData(client,(BYTE*)&header,sizeof(header));
	// 2 Ȼ������ļ�����
    CString strPath="c:/";
	strPath+=header.szName;//�ļ�·��
	BYTE* pData=(BYTE*)malloc(header.nLen);
	RecvData(client,pData,header.nLen);
	//3 �����ļ�
	CFile file;
	file.Open(strPath,
		CFile::modeCreate|CFile::modeWrite);
	file.Write(pData,header.nLen);
	file.Close();
	free(pData);
	
	// �ر�
	client.Close();

	CAsyncSocket::OnAccept(nErrorCode);
}

BOOL CServerSocket::RecvData(CSocket& client,
					   BYTE* pData,long nLen)
{	BYTE* pTmpData=pData;
	//ʣ��Ļ�û�н��յ����ݵĳ���
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