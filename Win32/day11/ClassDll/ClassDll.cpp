
#define DLLCLASS_EXPORTS
#include "ClassDll.h"
#include "windows.h"
#include <cstdio>

BOOL CALLBACK DllMain(HINSTANCE hDll,DWORD fdwReason,LPVOID reserve){
	
	switch(fdwReason){
	case DLL_PROCESS_ATTACH:
		//做初始化工作
		printf("Loading...\n");
		break;
	case DLL_PROCESS_DETACH:
		//善后处理工作
		printf("UnLoading...\n");
		break;
	}
	return true;
}




int CMath::Add(int add1,int add2){
	return add1 + add2;
}
int CMath::Sub(int sub1,int sub2){
	return sub1 - sub2;

}