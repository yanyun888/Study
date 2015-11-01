
#ifndef CLASSDLL_H
#define CLASSDLL_H

#ifdef DLLCLASS_EXPORTS
#define EXT_CLASS _declspec(dllexport)//DLL
#else
#define EXT_CLASS _declspec(dllimport)//使用者
#endif
//使用宏开关来确定导入和导出


class EXT_CLASS CMath{
public:
	int Add(int add1,int add2);
	int Sub(int sub1,int sub2);
};

#endif
