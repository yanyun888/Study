// WinChar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"


#define UNICODE
#include "windows.h"

void PrintUnicode(){
	HANDLE hSTD = GetStdHandle(STD_OUTPUT_HANDLE);
	for(WORD nHight = 100;nHight<200;++nHight){
		for(WORD nLow = 100; nLow<200;++nLow){
			wchar_t wChar = nHight*256 + nLow;
			WriteConsole(hSTD,&wChar,1,NULL,NULL);
		}
		printf("\n");
	}
}




void T_char(){
	TCHAR * pszText = __TEXT("hello");
#ifdef UNICODE
	wprintf( L"double:%s\n",pszText );
#else
	printf( "single:%s\n", pszText );
#endif

/*
#ifdef WIDECHAR
	wchar_t * pszText = L"hello";
	wprintf(L"%s\n", pszText);
#else
	char * pszText = "hello";
	printf("%s\n",pszText);
#endif
*/
}

void Ascii(){
	SetConsoleOutputCP( 437 ); //Ó¢ÎÄ´úÂëÒ³
	for(int i=0; i<256;++i){
		printf("%c ",i);
	}
}

void C_char(){
	char* pszText = "hello char";
	printf( "%s\n" , pszText );
}

void W_char(){
	wchar_t * pwszText = L"hello char";
	int nLen = wcslen(pwszText);
	wprintf( L"%s %d\n",pwszText,nLen);
}


int main(int argc, char* argv[])
{
//	Ascii();
//	C_char();
//	W_char();
//	T_char();
	PrintUnicode();

	return 0;
}
