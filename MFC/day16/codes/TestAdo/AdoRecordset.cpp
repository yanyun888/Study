// AdoRecordset.cpp: implementation of the CAdoRecordset class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestAdo.h"
#include "AdoRecordset.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdoRecordset::CAdoRecordset()
{

}

CAdoRecordset::~CAdoRecordset()
{

}
BOOL CAdoRecordset::OpenTable(CString strTable,
							  CAdoDatabase *pDB)
{
	HRESULT nRet=
		m_pSet.CreateInstance(__uuidof(Recordset));
	if (FAILED(nRet))
	{
		return FALSE;
	}
	nRet=m_pSet->Open(_variant_t(strTable),
                (IDispatch*)pDB->m_pConn,
				adOpenKeyset,adLockOptimistic,
				adCmdTable);
	if (FAILED(nRet))
	{
		return FALSE;
	}
	return TRUE;

		
}
long CAdoRecordset::GetFieldCount()
{
	return m_pSet->Fields->GetCount();
}
void CAdoRecordset::GetFieldName(long nIndex,
							CString& strName)
{
    strName=(LPSTR)
		m_pSet->Fields->GetItem(nIndex)->GetName();
}
void CAdoRecordset::GetFieldValue(long nIndex,
								  CString& strValue)
{
	_variant_t varValue=
		m_pSet->Fields->GetItem(nIndex)->Value;
	if (VT_NULL==varValue.vt)
	{
        strValue="";
	}
	else
	{
	    strValue=(LPSTR)(_bstr_t)varValue;
	}
}
void CAdoRecordset::SetFieldValue(long nIndex,
							CString strValue)
{
	m_pSet->Fields->GetItem(nIndex)->Value=
		_variant_t(strValue);

}
void CAdoRecordset::MoveFirst()
{
	m_pSet->MoveFirst();
}
void CAdoRecordset::MoveLast()
{
	m_pSet->MoveLast();
}
void CAdoRecordset::MoveNext()
{
	m_pSet->MoveNext();
}
void CAdoRecordset::MovePrevious()
{
	m_pSet->MovePrevious();
}
void CAdoRecordset::Move(long nNums)
{
	m_pSet->Move(nNums,(long)adBookmarkFirst);
}
BOOL CAdoRecordset::IsBOF()
{
	return m_pSet->BOF;
}
BOOL CAdoRecordset::IsEOF()
{
	return m_pSet->adoEOF;
}