// WinHeap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "windows.h"

void HeapInfo(){
	HANDLE hHeap = GetProcessHeap();
	printf("first:%d\n",hHeap);
	HANDLE hHeaps[25] = {0};
	DWORD nCount = GetProcessHeaps(25,hHeaps);
	for(DWORD i=0;i<nCount;++i){
		printf("%d - %d\n",i,hHeaps[i]);
	}
}

void Heap(){
	HANDLE hHeap = HeapCreate(HEAP_NO_SERIALIZE,1024*1024,0);
	
	char* pszText = (char*) HeapAlloc(hHeap,HEAP_ZERO_MEMORY,2*1024*1024);
	
	strcpy(pszText,"hello heap");
	printf("%s\n",pszText);
	HeapFree(hHeap,0,pszText);
	
	//将内核中的堆结构删除，同时彻底释放堆结构维护的内存
	HeapDestroy(hHeap);
	
}


int main(int argc, char* argv[])
{
	HeapInfo();
	return 0;
}
