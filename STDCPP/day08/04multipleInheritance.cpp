/* File Name: 04multipleInheritance.cpp
** Author: 
** Version: 
** Created Time: 15/09/14-16:12  */
 
 
#include <iostream>
using namespace std;

class Phone{
public:
	Phone(const string& number):m_number(number){}
	void call(const string& number){
		cout << m_number << " calling " << number << endl;
	}
private:
	string m_number;
};

class Player{
public:
	Player(const string& media):m_media(media){
	}
	void play(const string& music){
		cout << m_media << " playing " << music <<endl;
	}
private:
	string m_media;
};

class Computer{
public:
	Computer(const string& os):m_os(os){}
	void run(const string& app){
		cout <<"running "<< app << " on "<< m_os << endl;
	}
private:
	string m_os;
};

class Smartphone:public Phone,public Player,public Computer{
public:
	Smartphone(const string& number,const string& media,const string& os):
	Phone(number),Player(media),Computer(os){}
};

int main(){

	Smartphone sp("18710553082","mp4","Android");
	sp.call("010-10086");
	sp.play("小苹果");
	sp.run("AngryBirds");

	Smartphone *p = &sp;
	Phone *p2 = p;//static_cast<Phone*>(p);
	Player*  p3 = p;//static_cast<Player*>(p);
	Computer* p4 = p;//static_cast<Computer*>(p);
	cout << p << endl;
	cout <<p2 <<','<<p3 <<','<<p4 <<endl;

	return 0;
}

