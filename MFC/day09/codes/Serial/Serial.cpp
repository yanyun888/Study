// Serial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Serial.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;
// ¥Ê¥¢(–¥»Î)
void Store()
{
   CFile file;
   file.Open("c:/Serial.bin",
	   CFile::modeCreate|CFile::modeWrite);
   CArchive ar(&file,CArchive::store);
   ar<<100<<12.25<<'A';
   ar.Close();
   file.Close();
}
//º”‘ÿ(∂¡»°)
void Load()
{
   CFile file;
   file.Open("c:/Serial.bin",CFile::modeRead);
   CArchive ar(&file,CArchive::load);
   int nValue=0;
   double dValue=0.0;
   char cValue;
   ar>>nValue>>dValue>>cValue;
   ar.Close();
   file.Close();
   printf("nValue=%d\n",nValue);
   printf("dValue=%lf\n",dValue);
   printf("cValue=%c\n",cValue);

}
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	Store();
	Load();
	

	return 0;
}
