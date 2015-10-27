/* File Name: h1.h
** Author: 
** Version: 
** Created Time: 15/09/15-17:11  */
 
 
#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
using namespace std;

enum GRADE{MANAGER,TECHNICAN,SALESMAN,TECHMANAGER,SALESMANAGER,EMPLOYEE=0};

class Employee{
public:
	Employee(const string& name="",int no=0,GRADE grade=EMPLOYEE)
		:m_name(name),m_no(no),m_grade(grade){}
	virtual double bonus(void) = 0;
	virtual void show(void) = 0;
protected:
	double m_attend;//出勤率
private:
	string m_name;
	int m_no;
	int m_grade;
};

class Manager:virtual public Employee{
public:
	Manager(const string& name="",int no=0,GRADE grade=MANAGER,double commission=5000,
			double commissionPCT=2):Employee(name,no,grade),m_commission(commission),
			m_commissionPCT(commissionPCT){}
	void setPct(void);
	void setCommission(void);
	double bonus(void);
	void show(void);
private:
	double m_commission;
	double m_commissionPCT;
};
class Technican:virtual public Employee{
public:
	Technican(const string& name="",int no=0,GRADE grade=TECHNICAN,
		double allowance=5000,int hourNumber=30,double progressPCT=0.8):
		Employee(name,no,grade),m_allowance(allowance),m_hourNumber(hourNumber),
		m_progressPCT(progressPCT){ }
	void setHour(void);
	void setProgressPCT(void);
	double bonus(void);
	void show(void);
private:
	double m_allowance;
	int m_hourNumber;
	double m_progressPCT;
};

class Salesman:virtual public Employee{
public:
	Salesman(const string& name="",int no=0,GRADE grade=SALESMAN,double salesSum=0,
			double salesPCT=0.1):
		Employee(name,no,grade),m_salesSum(salesSum),m_salesPCT(salesPCT){}
	void setSalesSum(void);
	void setSalesPCT(void);
	double bonus(void);
	void show();
private:
	double m_salesSum;
	double m_salesPCT;
};


class Techmanager:public Technican,public Manager{
public:
	Techmanager(const string& name="",int no=0,GRADE grade=TECHMANAGER,
		double commission=5000,double commissionPCT=2,//Manager
		double allowance=5000,int hourNumber=30,double progressPCT=0.8)://Technican
		Manager(name,no,grade,commission,commissionPCT),
		Technican(name,no,grade,allowance,hourNumber,progressPCT),
		Employee(name,no,grade){}
	double bonus(void);
	void show(void);
};


class Salesmanager:public Salesman,public Manager{
public:

	Salesmanager(const string& name="",int no=0,GRADE grade=SALESMANAGER,
		double salesSum=1000000,double salesPCT=0.1,
		double commission=5000,double commissionPCT=2):
		Salesman(name,no,grade,salesSum,salesPCT),
		Manager(name,no,grade,commission,commissionPCT),
		Employee(name,no,grade){}
	double bonus(void);
	void show();
					
};




#endif

