// WinCreate.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "stdio.h"
#include "resource.h"

HINSTANCE g_hInstance = 0;
HANDLE g_hOutput = 0;
int g_kind = 0;

void OnCommand(HWND hWnd,WPARAM wParam){
	g_kind = LOWORD(wParam);
	switch(LOWORD(wParam)){
		case ID_POINT://画图要在绘图消息里画
		case ID_LINE:
		case ID_RECT:
		case ID_ROUNDRECT:
		case ID_CIRCLE:
		case ID_ARC:
		case ID_BMP:
			InvalidateRect(hWnd,NULL,true);//触发绘图消息出现
			break;
	}
}

void DrawPoint(HDC hdc){
	//SetPixel(hdc,100,100,RGB(255,0,0));
	for(int i=0;i<256;++i){
		for(int j=0;j<256;++j){
			SetPixel(hdc,i,j,RGB(255,i,j));
			SetPixel(hdc,i+256,j,RGB(i,j,256));
		}
	}
}
void DrawLine(HDC hdc){
	MoveToEx(hdc,100,100,NULL);
	LineTo(hdc,300,300);
	LineTo(hdc,600,300);
}
void DrawRect(HDC hdc){
	Rectangle(hdc,100,100,300,300);
}
void DrawRoundRect(HDC hdc){
	RoundRect(hdc,100,100,300,300,50,50);
}
void DrawCircle(HDC hdc){
	Ellipse(hdc,100,100,300,300);
	Ellipse(hdc,310,100,500,300);
}
void DrawArc(HDC hdc){
	Arc(hdc,100,100,300,300,100,100,300,300);
}
void DrawBmp(HDC hdc){
	//1.添加位图资源
	//2.加载位图
	HBITMAP hBmp = LoadBitmap(g_hInstance,MAKEINTRESOURCE(IDB_BITMAP1));
	
	BITMAP bmpinfo = {0};
	GetObject(hBmp,sizeof(bmpinfo),&bmpinfo);

	//创建一个内存DC，同时在内存中构建一个虚拟区域
	HDC hMemdc = CreateCompatibleDC(hdc);
	
	//将位图的数据，送给内存DC，内存DC立即将图像在虚拟区域中绘制出来
//	HGDIOBJ nOldBmp = SelectObject(hdc,hBmp);
	HGDIOBJ nOldBmp = SelectObject(hMemdc,hBmp);



	//1:1 成像
	//绘图设备实际上就是一个内核的结构
	//将内存DC维护的数据已拷贝内存的方式，一次性扔到当前DC维护的显存中
	BitBlt(hdc,0,0,bmpinfo.bmWidth,bmpinfo.bmHeight,hMemdc,0,0,SRCCOPY);
	StretchBlt(hdc,bmpinfo.bmWidth,bmpinfo.bmHeight,200,200,hMemdc,0,0,100,100,SRCCOPY);

	SelectObject(hMemdc,nOldBmp);
	DeleteObject(hBmp);
	DeleteDC(hMemdc);


}

void OnPaint(HWND hWnd){
	PAINTSTRUCT ps = {0};
	HDC hdc = BeginPaint(hWnd,&ps);
	
	HPEN hPen = CreatePen(PS_DASH,10,RGB(255,0,0));
	//HBRUSH hBrush = CreateSolidBrush(RGB(0,255,0));
	//HGDIOBJ hBrush = GetStockObject(NULL_BRUSH);
	
	HBITMAP hBmp = LoadBitmap(g_hInstance,MAKEINTRESOURCE(IDB_BITMAP1));
	HBRUSH hBrush = CreatePatternBrush(hBmp);


	HGDIOBJ nOldPen = SelectObject(hdc,hBrush);

	int nOldMode = SetMapMode(hdc,MM_ISOTROPIC);
	SetWindowExtEx(hdc,1,1,NULL);
	SetViewportExtEx(hdc,1,2,NULL);

	switch(g_kind){
		case ID_ARC:
			DrawArc(hdc);
			break;
		case ID_POINT:
			DrawPoint(hdc);
			break;
		case ID_LINE:
			DrawLine(hdc);
			break;
		case ID_RECT:
			DrawRect(hdc);
			break;
		case ID_ROUNDRECT:
			DrawRoundRect(hdc);
			break;
		case ID_CIRCLE:
			DrawCircle(hdc);
			break;
		case ID_BMP:
			DrawBmp(hdc);
			break;
	}
	SelectObject(hdc,nOldPen);
	//DeleteObject(hPen);
	SetMapMode(hdc,nOldMode);
	EndPaint(hWnd,&ps);
}


//窗口处理函数(自定义函数，处理消息)
LRESULT CALLBACK WndProc(HWND hWnd,
						 UINT msgID,
						 WPARAM wParam,
						 LPARAM lParam
						 ){
	switch(msgID)
	{
	case WM_PAINT:
		OnPaint(hWnd);
		break;
	case WM_COMMAND:
		OnCommand(hWnd,wParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd,msgID,wParam,lParam);

}
void Regsiter (LPSTR lpClassName, WNDPROC wndproc) {
	WNDCLASSEX wce = {0};
	wce.cbSize = sizeof(wce);
	wce.cbClsExtra = 0;
	wce.cbWndExtra = 0;
	wce.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hIconSm = NULL;
	wce.hInstance = g_hInstance;
	wce.lpfnWndProc = WndProc;
	wce.lpszClassName = lpClassName;
	wce.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wce.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClassEx(&wce);
}

HWND CreateMain (LPSTR lpClassName,LPSTR lpWndName){
	HWND hWnd = CreateWindowEx(0,lpClassName,lpWndName,WS_OVERLAPPEDWINDOW,
		100,100,700,500,NULL,NULL,g_hInstance,NULL);
	return hWnd;
}

void Display(HWND hWnd){
	ShowWindow(hWnd,SW_SHOW);
	UpdateWindow(hWnd);
}

void Message(){
	MSG nMsg = {0};
	while(GetMessage(&nMsg,NULL,0,0)){
		TranslateMessage(&nMsg);
		DispatchMessage(&nMsg);
	}
}


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	AllocConsole();
	g_hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 	g_hInstance = hInstance; //保存当前程序实例句柄
	Regsiter("Main",WndProc);
	HWND hWnd = CreateMain("Main","Window");
	Display(hWnd);
	Message();
	return 0;
}




