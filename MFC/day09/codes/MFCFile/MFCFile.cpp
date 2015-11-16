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

//演示文件操作
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
	   // 1 输入异常信息...
	   
	   // 2 关闭文件 
	   file.Close();
   }
 
}
//文件信息的操作
void MFCFileStatus()
{
	CFileStatus status;
	CFile::GetStatus("c:/mfcfile.txt",status);
    CTimeSpan span(7,0,0,0);//时间段
	status.m_ctime-=span;
	CFile::SetStatus("c:/mfcfile.txt",status);


}
//文件查找操作
void MFCFileFind(CString strPath)
{
   // 1 开始查找
   CFileFind find;
   BOOL bRet=find.FindFile(strPath+"/*.*");
   while(bRet)
   {
	   // 2 查找当前文件信息，并返回下一个文件是否存在
	   bRet=find.FindNextFile();
	   // 3 获取或者判断文件信息
	   //CString strName=find.GetFileName();
	   strPath=find.GetFilePath();
	   if (!find.IsDots())
	   {
		   if (find.IsDirectory())
		   {
			   printf("目录:%s\n",strPath);
			   MFCFileFind(strPath);
		   }
		   else
		   {
			   printf("文件:%s\n",strPath);
		   }
	   }
	   
   }
   // 4 结束查找
   find.Close();

}
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	
	//MFCFile();
	//MFCFileStatus();
    MFCFileFind("e:/mfc"); 
	return 0;
}


