
#include"diamond.h"

void printDiamondEmpty(const unsigned size){
	for(unsigned i=0;i<size;++i){
		for(unsigned j=0;j<size*2;++j){
			if(i+j==size)
				printf("*");
			else if(j>size && j-i==size )
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	for(int i=size-2; i>=0;--i){
		for(int j=0;j<size*2;++j){
			if(i+j == size )
				printf("*");
			else if(j>size && j-i ==size)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
void printDiamondFull(const unsigned size){
	for(int i=0;i<size;++i){
		for(int j=0;j<size*2;++j){
			if(j<=size && i+j>=size)
				printf("*");
			else if(j>size && j-i<=size )
				printf("*");
			else
				printf(" ");
		}
		printf("\n");	
	}
	for(int i=size-2; i>=0;--i){
		for(int j=0;j<size*2;++j){
			if(j<=size && i+j >= size )
				printf("*");
			else if(j>size && j-i <=size)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}









