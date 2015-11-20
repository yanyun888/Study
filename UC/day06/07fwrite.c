
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){
	
	FILE* pf = fopen("num.dat","wb");
	time_t t1 = time(0);
	unsigned long int i;
	for(i=1;i<=1000000 ;i++){
		fwrite(&i,sizeof(unsigned long int),1,pf);
	}
	fclose(pf);
	time_t t2 = time(0);
	printf("%lf\n",difftime(t2,t1));

	return 0;
}

