

#include<stdio.h>
#include<time.h>




int main(){
	
	time_t t = time(0);
	struct tm * local = localtime(&t);
	printf("%d,%d,%d",1900+local->tm_year,1+local->tm_mon,local->tm_mday   );

	return 0;
}


