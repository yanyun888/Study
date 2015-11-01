

//隐式链接
#include <cstdio>

_declspec(dllimport) int CppDll_add(int ,int);
_declspec(dllimport) int CppDll_sub(int ,int);
_declspec(dllimport) int CppDll_mul(int ,int);

#pragma comment(lib,"../lib/CppDll.lib")
//通知链接器到哪抓函数的编号和CppDll.lib文件配套的dll文件名

int main(){

	int sum = CppDll_add(5,6);
	int sub = CppDll_sub(5,6);
	int mul = CppDll_mul(5,6);
	printf("sum=%d,sub=%d,mul=%d\n",sum,sub,mul);
	return 0;
}
