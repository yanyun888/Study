// AdoRecordset.cpp: implementation of the CAdoRecordset class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestADO.h"
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

BOOL CAdoRecordset::OpenTable(CString strTable, CAdoDatabase *pDB)
{
	HRESULT nRet = m_pSet.CreateInstance(__uuidof(Recordset));
	if(FAILED(nRet)){
		return false;
	}

	nRet = m_pSet->Open(_variant_t(strTable),
		(IDispatch*)pDB->m_pConn,
		adOpenKeyset,
		adLockOptimistic,
		adCmdTable);

	if(FAILED(nRet)){
		return false;
	}
	return true;
}

long CAdoRecordset::GetFieldCount()
{
	return m_pSet->Fields->GetCount();
}

void CAdoRecordset::GetFieldName(long nIndex, CString &strName)
{
	strName = (LPSTR) m_pSet->Fields->GetItem(nIndex)->GetName();
}
