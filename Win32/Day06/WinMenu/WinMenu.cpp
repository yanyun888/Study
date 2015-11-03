#include "stdafx.h"
#include "stdio.h"
HINSTANCE g_hInstance = 0;
HMENU hFile;
HANDLE g_hOutput = 0;
void OnCreate( HWND hWnd )
{
	HMENU hMain = CreateMenu( );

	hFile = CreatePopupMenu( );
	AppendMenu( hFile, MF_STRING|MF_CHECKED, 1003, "新建" );
	AppendMenu( hFile, MF_SEPARATOR, 0, "" );
	AppendMenu( hFile, MF_STRING|MF_MENUBARBREAK, 1004, "退出" );

	HMENU hHelp = CreatePopupMenu( );
	AppendMenu( hHelp, MF_STRING|MF_GRAYED, 1005, "关于" );

	AppendMenu( hMain, MF_POPUP, (UINT)hFile, "文件" );
	AppendMenu( hMain, MF_POPUP, (UINT)hHelp, "帮助" );
	SetMenu( hWnd, hMain );
}
int g_state = 0;//标志量（代表新建菜单项当前状态）
void OnCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
	case 1003:
		if( g_state==0 )
		{
			CheckMenuItem( hFile, 1003, 
					MF_BYCOMMAND|MF_UNCHECKED );
		}else{
			CheckMenuItem( hFile, 0,
					MF_BYPOSITION|MF_CHECKED );
		}
		g_state = !g_state;
		break;
	case 1004:
		MessageBox( hWnd, "退出被点击", "Infor", MB_OK );
		break;
	case 1005:
		MessageBox( hWnd, "关于被点击", "Infor", MB_OK );
		break;
	}
}
void OnInitMenuPopup( HWND hWnd, WPARAM wParam, 
					 LPARAM lParam )
{
	char szText[256] = { 0 };
	sprintf( szText, 
		"即将显示的菜单句柄:%d,被点击的顶层菜单项索引:%d,即将显式的菜单是否为窗口菜单:%d\n",
		wParam, LOWORD(lParam), HIWORD(lParam) );
	WriteConsole( g_hOutput, szText, strlen(szText),
					NULL, NULL );
}
//窗口处理函数(自定义函数,处理消息)
LRESULT CALLBACK WndProc( HWND hWnd, UINT msgID,
						 WPARAM wParam, LPARAM lParam )
{
	switch( msgID )
	{
	case WM_INITMENUPOPUP:
		OnInitMenuPopup( hWnd, wParam, lParam );
		break;
	case WM_COMMAND:
		OnCommand( hWnd, wParam );
		break;
	case WM_CREATE:
		OnCreate( hWnd );
		break;
	case WM_DESTROY:
		PostQuitMessage( 0 );
		break;
	}
	return DefWindowProc( hWnd, msgID, wParam, lParam );
}
//注册窗口类
void Register( LPSTR lpClassName, WNDPROC wndproc )
{
	WNDCLASSEX wce = { 0 };
	wce.cbSize = sizeof( wce );
	wce.cbClsExtra = 0;
	wce.cbWndExtra = 0;
	wce.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hIconSm = NULL;
	wce.hInstance = g_hInstance;
	wce.lpfnWndProc = wndproc;
	wce.lpszClassName = lpClassName;
	wce.lpszMenuName = NULL;
	wce.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClassEx( &wce );
}
//创建主窗口
HWND CreateMain( LPSTR lpClassName, LPSTR lpWndName )
{
	HWND hWnd = CreateWindowEx( 0, lpClassName, lpWndName,
		WS_OVERLAPPEDWINDOW, 100, 100, 700, 500,
		NULL, NULL, g_hInstance, NULL );
	return hWnd;
}
//显式窗口
void Display( HWND hWnd )
{
	ShowWindow( hWnd, SW_SHOW );
	UpdateWindow( hWnd );
}
//消息循环
void Message( )
{
	MSG nMsg = { 0 };
	while( GetMessage(&nMsg,NULL,0,0) )
	{
		TranslateMessage( &nMsg );
		DispatchMessage( &nMsg );//将消息交给窗口处理函数
	}
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	AllocConsole( );
	g_hOutput = GetStdHandle( STD_OUTPUT_HANDLE );
	g_hInstance = hInstance;//保存当前程序实例句柄
	Register( "Main", WndProc );
	HWND hWnd = CreateMain( "Main", "window" );
	Display( hWnd );
	Message( );
	return 0;
}



