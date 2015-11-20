
#include <cstdio>
#include "windows.h"
#include <iostream>
using namespace std;

typedef int(*DLL_FUNC)(int,int);

int main(){
	
	HMODULE hDll = LoadLibrary("CppDll.dll");
	printf("hDll:%p\n",hDll);
	std::cout << "dynamic library load successfully" << std::endl;
	
	DLL_FUNC myAdd = (DLL_FUNC)GetProcAddress(hDll,"CppDll_add");
	printf("myAdd:%p\n",myAdd);
	int sum = myAdd(5,8);
	printf("sum=%d\n",sum);
	
	DLL_FUNC mySub = (DLL_FUNC)GetProcAddress(hDll,"CppDll_sub");
	printf("mySub:%p\n",mySub);
	int sub = mySub(5,8);
	printf("sub=%d\n",sub);

	DLL_FUNC myMul = (DLL_FUNC)GetProcAddress(hDll,"?CppDll_mul@@YAHHH@Z");
	printf("myMul:%p\n",myMul);
	int mul = myMul(5,8);
	printf("mul=%d\n",mul);

	FreeLibrary(hDll);

	return 0;
}

