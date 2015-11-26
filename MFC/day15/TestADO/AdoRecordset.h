// AdoRecordset.h: interface for the CAdoRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADORECORDSET_H__4ACF2FA9_5931_4631_844B_6C2FA5E75855__INCLUDED_)
#define AFX_ADORECORDSET_H__4ACF2FA9_5931_4631_844B_6C2FA5E75855__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AdoDatabase.h"

class CAdoRecordset  
{
public:
	CAdoRecordset();
	virtual ~CAdoRecordset();

public:
	//获取字段的名称
	void GetFieldName(long nIndex,CString& strName);

	//获取字段的数量
	long GetFieldCount();
	BOOL OpenTable(CString strTable, CAdoDatabase *pDB);
	_RecordsetPtr m_pSet;
};

#endif // !defined(AFX_ADORECORDSET_H__4ACF2FA9_5931_4631_844B_6C2FA5E75855__INCLUDED_)
