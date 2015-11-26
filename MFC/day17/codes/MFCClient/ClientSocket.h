#if !defined(AFX_CLIENTSOCKET_H__70616C21_8E84_418A_8B88_40D768B3169A__INCLUDED_)
#define AFX_CLIENTSOCKET_H__70616C21_8E84_418A_8B88_40D768B3169A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target

class CClientSocket : public CSocket
{
// Attributes
public:
    // 1 初始化客户端
	BOOL InitClient(char *IP,UINT nPort);
	// 2 发送数据
	BOOL SendData(BYTE* pData,long nLen);
	// 3 发送文件
	BOOL SendFile(CString strPath);
// Operations
public:
	CClientSocket();
	virtual ~CClientSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSocket)
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCKET_H__70616C21_8E84_418A_8B88_40D768B3169A__INCLUDED_)
