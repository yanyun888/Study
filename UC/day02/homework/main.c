

#include<stdio.h>
#include"diamond.h"

int main(){

	int size = 0;
	printf("please input size of diamond:");
	scanf("%d",&size);
	printDiamondEmpty(size);
	printf("\n");

	printDiamondFull(size);

	return 0;
}

