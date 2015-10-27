/* File Name: 01shape.cpp
** Author: 
** Version: 
** Created Time: 15/09/15-10:10  */
 
 
#include <iostream>
using namespace std;

class Shape{
public:
	Shape(int x,int y):m_x(x),m_y(y){}
	/*
	virtual void draw(void){
		cout << "图形(" << m_x <<',' <<m_y <<')'<<endl;
	}
	*/
	virtual void draw(void) = 0;
protected:
	int m_x;
	int m_y;
};
class Rect:public Shape{
public:
	Rect(int x,int y,int w,int h):Shape(x,y),m_w(w),m_h(h){}
	void draw(void){
		cout << "矩形(" << m_x <<','<<m_y<<"),("<<m_w<<','<<m_h<<')'<<endl;
	}
private:
	int m_w;
	int m_h;
};

class Circle:public Shape{
public:
	Circle(int x,int y,int r):Shape(x,y),m_r(r){}
	void draw(void){
		cout << "圆形(" << m_x <<','<<m_y<<"),("<<m_r<<')'<<endl;
	}
private:
	int m_r;
};

void render(Shape* shapes[]){
	for(size_t i=0;shapes[i];++i){
		shapes[i]->draw();
	}
}

int main(){

	Shape* shapes[100]={0};
	shapes[0] = new Rect(1,2,3,4);
	shapes[1] = new Rect(5,6,7,8);
	shapes[2] = new Circle(1,2,3);
	shapes[3] = new Rect(1,2,3,4);
	shapes[4] = new Circle(11,12,13);
	//shapes[5] = new Shape(1,2);
	render(shapes);


	return 0;
}

