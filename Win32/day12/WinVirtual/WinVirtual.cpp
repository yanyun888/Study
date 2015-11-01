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
	MEM_COMMIT - 连地址带内存都要
	MEM_RESERVE - 只要地址不要内存
*/
	Status();
	VirtualFree(pszText,0,MEM_RELEASE);
/*
	MEM_DECOMMIT - 只释放内存,不释放地址
	MEM_RELEASE - 地址和内存都释放
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
