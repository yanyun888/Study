// DataType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <atlbase.h>
#include <comdef.h>

//activeX template library

void BSTRTest(){
	//1 ����
	BSTR text1 = SysAllocString(L"Hello World");

	//2 ʹ��

	//3 �ͷ�
	SysFreeString(text1);

	CComBSTR text2("Hello World");

	printf("%d\n",text2.Length());

	_bstr_t text3("Hello World");
	
	printf("%d\n",text3.length());

}


void VariantTest(){
	//ʹ�ÿɱ����͵ı�������ʾ����100
	VARIANT varInt;
	varInt.vt = VT_I4;
	varInt.lVal = 100;

	//ʹ������ʾָ��������ָ��
	
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

