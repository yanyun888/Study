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
	//�򿪱�
	BOOL OpenTable(CString strTable,CAdoDatabase *pDB);
    // ��ȡ�ֶ�����
	long GetFieldCount();
	// ����������ȡ�ֶε�����
	void GetFieldName(long nIndex,CString& strName);
    // ��ȡ�ֶε�ֵ
	void GetFieldValue(long nIndex,CString& strValue);
	// �����ֶε�ֵ
	void SetFieldValue(long nIndex,CString strValue);
    //��¼����ָ�����
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
