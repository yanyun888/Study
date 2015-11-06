// MFCDynCreate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MFCDynCreate.h"


class CAnimal:public CObject{
DECLARE_DYNCREATE(CAnimal)

};
IMPLEMENT_DYNCREATE(CAnimal,CObject)

class CDog:public CAnimal{
//DECLARE_DYNCREATE(CDog)
//DECLARE_DYNAMIC(class_name)
public:
	static const AFX_DATA CRuntimeClass classCDog; 
	virtual CRuntimeClass* GetRuntimeClass() const; 
	static CObject* PASCAL CreateObject();
};
//IMPLEMENT_DYNCREATE(CDog,CAnimal)
CObject* PASCAL CDog::CreateObject(){
	return new CDog; 
}
//IMPLEMENT_RUNTIMECLASS(CDog, CAnimal, 0xFFFF, CDog::CreateObject)
AFX_COMDAT const AFX_DATADEF CRuntimeClass CDog::classCDog = { 
		"CDog",
		sizeof(class CDog),
		0xFFFF,
		CDog::CreateObject, 
		RUNTIME_CLASS(CAnimal),
		NULL
}; 
CRuntimeClass* CDog::GetRuntimeClass() const {
	return RUNTIME_CLASS(CDog); 
} 

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[]){
	CObject* pObj = RUNTIME_CLASS(CDog)->CreateObject();
	if(pObj->IsKindOf(RUNTIME_CLASS(CObject)) ){
		printf("%#p\n",pObj);
	}
	return 0;
}


