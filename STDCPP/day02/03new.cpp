/* File Name: 03new.cpp
** Author: 
** Version: 
** Created Time: 15/09/06-11:25  */
 
 
#include <iostream>
using namespace std;

int main(){

#if 0
	int *pi = new int;
	cout<< *pi <<endl;
	delete pi;
	pi=NULL;
#else
	int *pi2 = new int(100);
	cout << *pi2 <<' '<<pi2<< endl;
	(*pi2)++;
	cout << *pi2 <<' '<<pi2<< endl;
	delete pi2;
//	pi2 = NULL; delete之后要置空
	cout << *pi2 <<' '<<pi2<< endl;//


#endif

	int *parr = new int[10]{1,2,3,4,5};
	for(int i=0;i<10;i++){
	//	parr[i]=i+1;
	}
	for(int i=0;i<10;i++){
		cout<<parr[i]<<" ";
	}
	delete[] parr; //这是的释放要注意
	parr = NULL;


	return 0;
}
