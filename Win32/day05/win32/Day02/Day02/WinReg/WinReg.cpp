#include "stdafx.h"

HINSTANCE g_hInstance = 0;
void SysReg( )
{ 
	//����Ҫע��
	HWND hWnd = CreateWindow( "EDIT", "OK", 
			WS_OVERLAPPEDWINDOW, 100, 100, 500, 500,
			NULL, NULL, g_hInstance, NULL );
	ShowWindow( hWnd, SW_SHOW );
	MSG nMsg = { 0 };
	while( GetMessage(&nMsg, NULL, 0, 0) )
	{
		TranslateMessage( &nMsg );
		DispatchMessage( &nMsg );
	}
}
void AppReg( )
{
	WNDCLASSEX wce = { 0 };
	wce.cbSize = sizeof( wce );
	wce.cbClsExtra = 0;
	wce.cbWndExtra = 0;
	wce.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hIconSm = NULL;
	wce.hInstance = g_hInstance;/************/
	wce.lpfnWndProc = DefWindowProc;
	wce.lpszClassName = "Main";/************/
	wce.lpszMenuName = NULL;
	wce.style = CS_HREDRAW | CS_VREDRAW; 
	RegisterClassEx( &wce );
	//���������и�ֵȫ��д�����ϵͳ
	HWND hWnd = CreateWindow( "Main", "window", WS_OVERLAPPEDWINDOW,
					100, 100, 500, 500, NULL, NULL,
					g_hInstance, NULL );
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	g_hInstance = hInstance;//���浱ǰ����ʵ�����
 //	SysReg( );
	AppReg( );
	return 0;
}



