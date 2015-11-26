


#include<stdio.h>
#include<dlfcn.h>

int main(){
	int size = 0;
	printf("please input diamond size:");
	scanf("%d",&size);

	void *handle = dlopen("libdiamond.so",RTLD_LAZY);
	if( !handle ){
		fprintf(stderr,"dlopen:%s\n",dlerror());
	}
	void (*p_printDiamond)(const int);
	p_printDiamond = dlsym(handle,"printDiamondEmpty"); 
	p_printDiamond(size);
	p_printDiamond = dlsym(handle,"printDiamondFull"); 
	p_printDiamond(size);
	if(dlclose(handle)){
		fprintf(stderr,"dlclose:%s\n",dlerror());
	}
	return 0;
}




