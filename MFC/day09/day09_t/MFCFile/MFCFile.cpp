// MFCFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//�ļ���Ϣ
void MFCFileStatus(){
	CFileStatus status;
	CFile::GetStatus("d:/mfcfile.txt");
	CTime t = CTime::GetCurrentTime();
	CTimeSpan span(7,0,0,0); // ʱ���
	status.m_ctime-=span;
	
}

void MFCFileFind(){




}

int _tmain(int argc, char* argv[])
{
	
	return 0;
}
