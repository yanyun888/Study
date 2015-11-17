// DataType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <atlbase.h>
#include <comdef.h>

//activeX template library

void BSTRTest(){
	//1 创建
	BSTR text1 = SysAllocString(L"Hello World");

	//2 使用

	//3 释放
	SysFreeString(text1);

	CComBSTR text2("Hello World");

	printf("%d\n",text2.Length());

	_bstr_t text3("Hello World");
	
	printf("%d\n",text3.length());

}


void VariantTest(){
	//使用可变类型的变量，表示整数100
	VARIANT varInt;
	varInt.vt = VT_I4;
	varInt.lVal = 100;

	//使用它表示指向整数的指针
	
	long nValue = 1000;
	varInt.vt = VT_BYREF| VT_I4 ;
	varInt.plVal = &nValue;



	CComBSTR varInt2(100);
	_variant_t varInt3(100l);

}


int main(int argc, char* argv[])
{
	BSTRTest();
	printf("Hello World!\n");
	return 0;
}

