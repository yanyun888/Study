/* File Name: 02clock.cpp
** Author: 
** Version: 
** Created Time: 15/09/08-10:06  */
 
 
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;


class Clock{

public:
	Clock(time_t now){
		cout << "构造函数初始化" << endl;
//		time_t now = time(0);
		struct tm* pt = localtime(&now);
		m_hour = pt->tm_hour;
		m_min = pt->tm_min;
		m_sec = pt->tm_sec;
		//setbuf(stdout,NULL);
	}
	void go(void){
		time_t tmp = 0;
		while(1){
			time_t t = time(0);
			struct tm* pt = localtime(&t);
			m_hour = pt->tm_hour;
			m_min = pt->tm_min;
			m_sec = pt->tm_sec;
			if(tmp != t){
				tmp = t;
				show();
			}
		}
	}
	void tick (void){
		sleep(1);
		if(++m_sec == 60 ){
			m_sec = 0;
			if(++m_min == 60){
				m_min = 0;
				if(++m_hour == 24)
					m_hour = 0;
			}
		}
	}
	void run(void){
		while(1){
			show();
			tick();
		}
	}

private:
	void show(void){
		system("clear");
		cout << m_hour <<":"<<m_min<<":"<<m_sec<<endl;
	}

	int m_hour;
	int m_min;
	int m_sec;
};

int main(){

	Clock c(time(NULL));
	c.go();

	return 0;
}
