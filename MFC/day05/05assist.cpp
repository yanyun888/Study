
//IsKindOf是如何做到判断的
yellowdog.IsKindOf(RUNTIME_CLASS(CObject)){ 
//函数内部this指针为yellowdog，函数的参数为链表尾结点
	
	CRuntimeClass* pClassThis = GetRuntimeClass();
	//获取&CDog::classDog(链表头结点)

	pClassThis->IsDerivedFrom( RUNTIME_CLASS(CObject) ){
		//函数内部this为链表头，参数为链尾结点
		const CRuntimeClass* pClassThis = this; //获取链表头
		
		while (pClassThis != NULL){
			if (pClassThis == pBaseClass)
			return TRUE;	
			pClassThis = pClassThis->m_pBaseClass;
		}
		return FALSE;
		//循环遍历链表的每个结点，将每个结点都和目标进行比对，只要有一
	}
}



CObject* pObj = RUNTIME_CLASS(CDog)->CreateObject(){
	// 函数内部this指针为&CDog::classCDog(链表头结点)
	pObject = (*m_pfnCreateObject)(){
		//调用CDog::CreateObject
		return new CDog;
	}
}


