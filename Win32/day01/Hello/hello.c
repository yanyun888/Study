

#include "windows.h"

int WinMain(HINSTANCE hIns, HINSTANCE hPrevIns, LPSTR lpCmdLine, int nCmdShow){
    MessageBox(NULL,"hello world","Information",MB_ABORTRETRYIGNORE|MB_ICONERROR);
    return 0;
}