/* File Name: 07format.cpp
** Author: 
** Version: 
** Created Time: 15/09/17-14:12  */
 
 
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	cout << sqrt(200) <<endl;
	cout.precision(10);
	cout << sqrt(200) <<endl;

	cout <<'[';
	cout.width(15); //这里仅仅是一次生效的
	cout.fill('*');
	cout <<sqrt(200) <<']'<<endl;
	cout << '[';
	cout.fill('*');
	cout <<sqrt(200) <<']'<<endl;

	cout.setf(ios::showpos);//显示正号
	cout.setf(ios::internal);//内插对齐
	cout << '['<<sqrt(200) <<']'<<endl;
	


	return 0;
}

