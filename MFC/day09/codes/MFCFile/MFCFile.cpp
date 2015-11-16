// MFCFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MFCFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

//��ʾ�ļ�����
void MFCFile()
{
   CFile file;
   try
   {
	   file.Open("c:/mfcfile.txt",
		   CFile::modeCreate|CFile::modeReadWrite);
	   char szWrite[]="Hello,MFCFile!";
	   file.Write(szWrite,strlen(szWrite));
	   char szRead[256]={0};
	   file.SeekToBegin();
	   int nRead=file.Read(szRead,256);
       file.Close();
	   printf("%s,Len=%d\n",szRead,nRead);
   }
   catch (CFileException* e)
   {
	   // 1 �����쳣��Ϣ...
	   
	   // 2 �ر��ļ� 
	   file.Close();
   }
 
}
//�ļ���Ϣ�Ĳ���
void MFCFileStatus()
{
	CFileStatus status;
	CFile::GetStatus("c:/mfcfile.txt",status);
    CTimeSpan span(7,0,0,0);//ʱ���
	status.m_ctime-=span;
	CFile::SetStatus("c:/mfcfile.txt",status);


}
//�ļ����Ҳ���
void MFCFileFind(CString strPath)
{
   // 1 ��ʼ����
   CFileFind find;
   BOOL bRet=find.FindFile(strPath+"/*.*");
   while(bRet)
   {
	   // 2 ���ҵ�ǰ�ļ���Ϣ����������һ���ļ��Ƿ����
	   bRet=find.FindNextFile();
	   // 3 ��ȡ�����ж��ļ���Ϣ
	   //CString strName=find.GetFileName();
	   strPath=find.GetFilePath();
	   if (!find.IsDots())
	   {
		   if (find.IsDirectory())
		   {
			   printf("Ŀ¼:%s\n",strPath);
			   MFCFileFind(strPath);
		   }
		   else
		   {
			   printf("�ļ�:%s\n",strPath);
		   }
	   }
	   
   }
   // 4 ��������
   find.Close();

}
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	
	//MFCFile();
	//MFCFileStatus();
    MFCFileFind("e:/mfc"); 
	return 0;
}


