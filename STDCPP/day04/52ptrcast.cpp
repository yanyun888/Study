/* File Name: 52ptrcast.cpp
** Author: 
** Version: 
** Created Time: 15/09/08-18:54  */
 
 
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int main(){
	
	int* pi = new int;
	float* pf = new float;
	double* pd = new double;
	void* pv = new int;
	pv = pf;

	
	//pf = pd; 由于pf和pd指向的内存块大小不同

	pv = pd; // 可以把任意类型的指针隐式地转化为void*类
	double* pt = static_cast<double*>(malloc(4)); //不能直接将void* 转化为double*

	int* pi2 = new float;

	cout << "sizeof(double)=" <<sizeof(double)<<endl;
	cout << "sizeof(float)=" <<sizeof(float)<<endl;


	return 0;
}
