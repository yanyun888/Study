/* File Name: 04pdf.cpp
** Author: 
** Version: 
** Created Time: 15/09/15-15:06  */
 
 
#include <iostream>
using namespace std;

//好莱坞模式
class PdfParser{
public:
	void parse(const char* pdffile){
		//解析出一个矩形
		onRect();
		//解析出一个圆形
		onCircle();
		//解析出一行文本
		onText();
		//解析出一张图片
		onImage();
	}
private:
	virtual void onRect(void) = 0;
	virtual void onCircle(void) = 0;
	virtual void onText(void) = 0;
	virtual void onImage(void) = 0;
};

class PdfRender:public PdfParser{

public:

private:
	virtual void onRect(void) {}
	virtual void onCircle(void) {}
	virtual void onText(void) {}
	virtual void onImage(void) {}

};



int main(){
	
	PdfRender render;
	render.parse("xxxpdf");


	return 0;
}

