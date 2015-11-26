
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>


int main(){

	char* p = (char*) malloc(-1);
	if(!p){
		fprintf(stderr,"malloc: %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}

	scanf(" %s",p);
	printf("%s\n",p);

	return 0;
}



