// AdoDatabase.cpp: implementation of the CAdoDatabase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestADO.h"
#include "AdoDatabase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdoDatabase::CAdoDatabase()
{

}

CAdoDatabase::~CAdoDatabase()
{
	CloseMDB();
}

BOOL CAdoDatabase::OpenMDB(CString strPath){
	HRESULT nRet = m_pConn.CreateInstance(__uuidof(Connection));
	if(FAILED(nRet)){
		return false;
	}

	CString strConn;
	strConn.Format("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s",strPath);
	nRet = m_pConn->Open(_bstr_t(strConn),"","",-1);

	if(FAILED(nRet)){
		return false;
	}
	return true;
}

BOOL CAdoDatabase::CloseMDB(){
	m_pConn ->Close();
	return true;
}
