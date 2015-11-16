// ObjectSerial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ObjectSerial.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

// 1 ����֧�����л�����
class CStudent:public CObject
{
public:
	CStudent(){}
	CStudent(CString strName,int nAge):m_strName(strName),
		m_nAge(nAge){}
	void Show()
	{
		printf("������%s\n",m_strName);
		printf("���䣺%d\n",m_nAge);
	}
	//�ں����У������ĳ�Ա���������л�
	virtual void Serialize( CArchive& ar );

private:
	CString m_strName;
	int m_nAge;
//DECLARE_SERIAL(CStudent)
_DECLARE_DYNCREATE(CStudent) 
AFX_API friend CArchive& AFXAPI 
operator>>(CArchive& ar, CStudent* &pOb);
};
//IMPLEMENT_SERIAL(CStudent,CObject,1)
CObject* PASCAL CStudent::CreateObject() 
{ 
	return new CStudent; 
} 
_IMPLEMENT_RUNTIMECLASS(CStudent, CObject, 1, 
						CStudent::CreateObject) 

AFX_CLASSINIT _init_CStudent(RUNTIME_CLASS(CStudent));

CArchive& AFXAPI operator>>(CArchive& ar, 
							CStudent* &pOb) 
{ 
	pOb = (CStudent*) 
          ar.ReadObject(RUNTIME_CLASS(CStudent)); 
	return ar; 
} 


void CStudent::Serialize( CArchive& ar )
{
	if (ar.IsStoring())
	{
        ar<<m_strName<<m_nAge;
	}
	else
	{
		ar>>m_strName>>m_nAge;
	}
}
// 2.1 �洢����(д����)
void ObjStore(CStudent *pStu)
{
   CFile file;
   file.Open("c:/stu.dat",
	   CFile::modeCreate|CFile::modeWrite);
   CArchive ar(&file,CArchive::store);
   ar<<pStu;
   ar.Close();
   file.Close();
} 
// 2.2 ���ض���(������)
void ObjLoad()
{
   CFile file;
   file.Open("c:/stu.dat",CFile::modeRead);
   CArchive ar(&file,CArchive::load);
   CStudent *pStu=NULL;
   ar>>pStu;
   ar.Close();
   file.Close();
   if(pStu)
   {
	  pStu->Show();
	  delete pStu;
	  pStu=NULL;

   }

}
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
   
	CStudent stu("�ŷ�",30);
    ObjStore(&stu);
	ObjLoad();
	return 0;
}


