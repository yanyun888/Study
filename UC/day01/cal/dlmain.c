#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>


int main(){
	


	void* handle = dlopen("libmath.so",RTLD_LAZY);
	if(!handle){
		fprintf(stderr,"加载共享库失败\n");
		exit(EXIT_FAILURE);
	}
	double(*add)(double,double) = (double(*)(double,double))dlsym(handle,"add");
	if(!add){
		fprintf(stderr,"加载函数失败\n");
		exit(EXIT_FAILURE);
	}
	printf("resule=%g\n",add(5.2,6.1));

	fi(dlclose()){
		fprintf(stderr,"卸载共享库失败\n");
		exit(EXIT_FAILURE)
	}
	return 0;
}

