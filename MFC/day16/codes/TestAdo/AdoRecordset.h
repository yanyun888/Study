// AdoRecordset.h: interface for the CAdoRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADORECORDSET_H__9535FEE3_5E8C_4657_BF7D_0FE4FCB4B862__INCLUDED_)
#define AFX_ADORECORDSET_H__9535FEE3_5E8C_4657_BF7D_0FE4FCB4B862__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AdoDatabase.h"
class CAdoRecordset  
{
public:
	CAdoRecordset();
	virtual ~CAdoRecordset();
	//打开表
	BOOL OpenTable(CString strTable,CAdoDatabase *pDB);
    // 获取字段数量
	long GetFieldCount();
	// 根据索引获取字段的名称
	void GetFieldName(long nIndex,CString& strName);
    // 获取字段的值
	void GetFieldValue(long nIndex,CString& strValue);
	// 设置字段的值
	void SetFieldValue(long nIndex,CString strValue);
    //记录集的指针操作
	void MoveFirst();
	void MoveLast();
	void MovePrevious();
	void MoveNext();
	void Move(long nNums);
	BOOL IsEOF();
	BOOL IsBOF();

public:
	_RecordsetPtr m_pSet;
};

#endif // !defined(AFX_ADORECORDSET_H__9535FEE3_5E8C_4657_BF7D_0FE4FCB4B862__INCLUDED_)
