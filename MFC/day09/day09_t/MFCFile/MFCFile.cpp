// MFCFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//文件信息
void MFCFileStatus(){
	CFileStatus status;
	CFile::GetStatus("d:/mfcfile.txt");
	CTime t = CTime::GetCurrentTime();
	CTimeSpan span(7,0,0,0); // 时间段
	status.m_ctime-=span;
	
}

void MFCFileFind(){




}

int _tmain(int argc, char* argv[])
{
	
	return 0;
}
