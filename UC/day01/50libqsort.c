
#include<stdio.h>
#include<stdlib.h>

static int cmp(const void* data1,const void* data2){
//	return *(int* const*)data1 < *(int* const*)data2;
	return *(int* const)data1 < *(int* const)data2;
}

int main(){
	
	int arr[] = {5,6,7,9,8,10,3,2,1,4};
	qsort(arr,10,sizeof(int),cmp);
	
	int i=0;
	for(i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
	
	printf("\n");

	return 0;
}



