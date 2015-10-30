#include "stdafx.h"
#include "stdio.h"
#define UNICODE
#include "windows.h"
#define WIDECHAR

void T_char( )
{
	TCHAR *pszText = __TEXT("hello");
#ifdef UNICODE
	wprintf( L"%s\n", pszText );
#else
	printf( "µ¥:%s\n", pszText );
#endif
/*
#ifdef WIDECHAR
	wchar_t *pszText = L"hello";
	wprintf( L"%s\n", pszText );
#else
	char *pszText = "hello";
	printf( "µ¥:%s\n", pszText );
#endif*/
}

void C_char( )
{
	char *pszText = "hello char";
	printf( "%s\n", pszText );
}
void W_char( )
{
	wchar_t *pszText = L"hello wchar";
	int nLen = wcslen( pszText );
	wprintf( L"%s %d\n", pszText, nLen );
}
void PrintUnicode( )
{
	HANDLE hStd = GetStdHandle( STD_OUTPUT_HANDLE );
	for( WORD nHigh=100; nHigh<200; nHigh++ )
	{
		for( WORD nLow=100; nLow<200; nLow++ )
		{
			wchar_t wChar = nHigh * 256 + nLow;
//			wprintf( L"%s", &wChar );
			WriteConsole( hStd, &wChar, 1, NULL, NULL );
		}
		printf( "\n" );
	}
}

int main(int argc, char* argv[])
{
//	T_char( );
//	C_char( );
//	W_char( );
	PrintUnicode( );
	return 0;
}
