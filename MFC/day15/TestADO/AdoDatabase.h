// AdoDatabase.h: interface for the CAdoDatabase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADODATABASE_H__01BAEC40_B586_4C0D_9824_16658B9EFBD2__INCLUDED_)
#define AFX_ADODATABASE_H__01BAEC40_B586_4C0D_9824_16658B9EFBD2__INCLUDED_

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
	BOOL CloseMDB();

public:
	_ConnectionPtr m_pConn;

};

#endif // !defined(AFX_ADODATABASE_H__01BAEC40_B586_4C0D_9824_16658B9EFBD2__INCLUDED_)
