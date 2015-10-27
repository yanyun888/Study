/* File Name: h1.cpp
** Author: 
** Version: 
** Created Time: 15/09/15-17:11  */
 
 
#include <iostream>
#include "employee.h"
using namespace std;

//enum GRADE{MANAGER,TECHNICAN,SALESMAN,TECHMANAGER,SALESMANAGER,EMPLOYEE};


void Manager::setPct(void){
	cout<<"原commissionPCT为:"<<m_commissionPCT<<endl;
	cout<<"请输入Manager的commissionPCT:";
	cin>>m_commissionPCT;
	cout<<"修改成功,现在commissionPCT为:"<<m_commissionPCT<<endl;
}
void Manager::setCommission(void){
	cout << "原commission为:"<<m_commission<<endl;
	cout<<"请输入Manager的commission:";
	cin>>m_commission;
	cout<<"修改成功,现在commission为:"<<m_commission<<endl;
}
double Manager::bonus(void){
	return m_commission*m_commissionPCT;
}
void Manager::show(void){

}
//
void Technican::setHour(void){
	cout << "原hourNumber为:"<<m_hourNumber<<endl;
	cout<<"请输入Technican的hourNumber:";
	cin>>m_hourNumber;
	cout<<"修改成功,现在hourNumber为:" << m_hourNumber << endl;
}
void Technican::setProgressPCT(void){
	cout << "原progressPCT为:" << m_progressPCT<<endl;
	cout << "请输入Technican的progressPCT:";
	cin >> m_progressPCT;
	cout << "修改成功,现在progressPCT为:" << m_progressPCT << endl;
}
double Technican::bonus(void){
	return m_allowance*m_hourNumber*m_progressPCT;
}

void Technican::show(void){
	cout<<"showing Technican:"<<endl;
/*	
	cout<<"name="<<m_name<<endl;
	cout<<"no="<<m_no<<endl;
	cout<<"grade="<<m_grade<<endl;
*/	
	cout<<"allowance="<<m_allowance<<endl;
	cout<<"hourNumber="<<m_hourNumber<<endl;
	cout<<"progress="<<m_progressPCT<<endl;
}

//
void Salesman::setSalesSum(void){
	cout << "原salesSum为:" << m_salesSum << endl;
	cout << "请输入Salesman的salesSum:";
	cin >> m_salesSum;
	cout << "修改成功,现在salesSum为:" << m_salesSum << endl;
}
void Salesman::setSalesPCT(void){
	cout << "原salesPCT为:" << m_salesPCT << endl;
	cout << "请输入Salesman的salesPCT:";
	cin >> m_salesPCT;
	cout << "修改成功,现在salesPCT为:" << m_salesPCT << endl;
}
double Salesman::bonus(void){
	return m_salesSum*m_salesPCT;
}
void Salesman::show(void){

}
//
double Techmanager::bonus(void){
	cout<<"Techmanager's bonus:"<<endl;
	cout<<"T_bonus:"<<Technican::bonus()<<endl;
	cout<<"M_bonus:"<<Manager::bonus()<<endl;
	return (this->Technican::bonus()+this->Manager::bonus())*0.5;
}
void Techmanager::show(void){


}
//

double Salesmanager::bonus(void){
	return (Salesman::bonus()+Manager::bonus())*0.5;
}
void Salesmanager::show(void){

}

