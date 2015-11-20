/*File Name: thread.cpp
**Author: 
**Version: 
**Created Time: 15/09/28-11:34  */
 
 
#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
using namespace std;

class Thread{
public:
	void start(void){
		pthread_create(&m_tid,NULL,run,this);
	}

private:
	static void* run (void* arg){
		((Thread*)arg)->run();
		return NULL;
	}
	virtual void run (void) = 0;
	pthread_t m_tid;
};


class AddThread:public Thread{
public:
	AddThread(useconds_t delay):m_delay(delay){}
private:
	void run(void){
		for(;;){
			cout << '+'<< flush;
			usleep(m_delay);
		}
	}
	useconds_t m_delay;
};

class SubThread:public Thread{
public:
	SubThread(useconds_t delay):m_delay(delay){	}
private:
	void run(void){
		for(;;){
			cout << '-' <<flush;
			usleep(50000);
		}
	}
	useconds_t m_delay;
};

int main(){
	AddThread add(50000);
	add.start();

	SubThread sub(100000);
	sub.start();

	getchar();
	return 0;
}
