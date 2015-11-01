// WinVirtual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "stdio.h"

void Status(){
	MEMORYSTATUS ms = {0};
	ms.dwLength = sizeof(ms);
	GlobalMemoryStatus(&ms);
	printf("Load:%d\n",ms.dwMemoryLoad);
	printf("TotalPhys:%u\n",ms.dwTotalPhys);
	printf("AvailPhys:%u\n",ms.dwAvailPhys);
	printf("TotalVirt:%u\n",ms.dwTotalPageFile);
	printf("AvailVirt:%u\n",ms.dwAvailPageFile);

	printf("TotalAddr:%u\n",ms.dwTotalVirtual);
	printf("AvailAddr:%u\n",ms.dwAvailVirtual);
	printf("-----------------------\n");

}

void VirtalInfo(){
	Status();
	char* pszText = (char*)VirtualAlloc(NULL,1024*1024*1024,MEM_COMMIT,PAGE_READWRITE);
/*
	MEM_COMMIT - ����ַ���ڴ涼Ҫ
	MEM_RESERVE - ֻҪ��ַ��Ҫ�ڴ�
*/
	Status();
	VirtualFree(pszText,0,MEM_RELEASE);
/*
	MEM_DECOMMIT - ֻ�ͷ��ڴ�,���ͷŵ�ַ
	MEM_RELEASE - ��ַ���ڴ涼�ͷ�
*/
	Status();
}
void VirtualCommit(){
	char* pszText = (char*) VirtualAlloc(NULL,4096,MEM_COMMIT,PAGE_READWRITE);
	
	printf("%s\n",pszText);
	strcpy(pszText,"hello commit");
	printf("%s\n",pszText);
	
	VirtualFree(pszText,0,MEM_RELEASE);
}

void VirtualReserve(){
	char* pszText = (char*) VirtualAlloc(NULL,1024*1024*1024,MEM_RESERVE,PAGE_READWRITE);

	char* pszText1 = (char*) VirtualAlloc(pszText,1,MEM_COMMIT,PAGE_READWRITE);

	printf("%p,%p\n",pszText,pszText1);
	strcpy(pszText,"hello reserve");
	printf("%s\n",pszText);

}


int main(int argc, char* argv[])
{
//	Status();
//	VirtalInfo();
	VirtualReserve();
	return 0;
}
