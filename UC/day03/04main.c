
#include<stdio.h>


int main(int argc,char* argv[],char* envp[]){

	for(int i=0; i<argc ;++i){
		printf("argv[%d]=%s\n",i,argv[i]);
	}
	extern char** environ;
	printf("%p,%p\n",envp,environ);
	return 0;
}
