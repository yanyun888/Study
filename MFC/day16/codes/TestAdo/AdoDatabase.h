// AdoDatabase.h: interface for the CAdoDatabase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADODATABASE_H__CFD7DF6B_8B14_4962_8C90_879F2532318B__INCLUDED_)
#define AFX_ADODATABASE_H__CFD7DF6B_8B14_4962_8C90_879F2532318B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAdoDatabase  
{
public:
	CAdoDatabase();
	virtual ~CAdoDatabase();
	//连接Access数据库
	BOOL OpenMDB(CString strPath);
	//关闭数据库
	void Close();
public:
	_ConnectionPtr m_pConn;
};

#endif // !defined(AFX_ADODATABASE_H__CFD7DF6B_8B14_4962_8C90_879F2532318B__INCLUDED_)
