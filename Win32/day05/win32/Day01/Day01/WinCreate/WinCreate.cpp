#include "stdafx.h"
//���ڴ�����(�Զ��壬������Ϣ)
LRESULT CALLBACK WndProc( HWND hWnd, UINT msgID,
						 WPARAM wParam, LPARAM lParam )
{
	return DefWindowProc( hWnd, msgID, wParam, lParam );
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	//ע�ᴰ����
	WNDCLASS wc = { 0 };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.hCursor = NULL;
	wc.hIcon = NULL;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = "Main";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass( &wc );//���������и�ֵȫ��д�����ϵͳ
	//���ڴ��д�������
	HWND hWnd = CreateWindow( "Main", "window", 
			WS_OVERLAPPEDWINDOW, 100, 100, 500, 500, 
			NULL, NULL, hInstance, NULL );
	//��ʾ����
	ShowWindow( hWnd, SW_SHOW );
	//��Ϣѭ��
	MSG nMsg = { 0 };
	while( GetMessage(&nMsg,NULL,0,0) )
	{
		TranslateMessage( &nMsg );
		DispatchMessage( &nMsg );
		//����Ϣ���� �Զ��崰�ڴ�����
	}
	return 0;
}



