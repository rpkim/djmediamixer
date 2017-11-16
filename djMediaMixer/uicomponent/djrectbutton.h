#pragma once
#include "ofMain.h"

enum DJBTNTYPE
{
	NORMAL = 0,
	TOGGLE = 1,
	ONE = 2,
	TWO = 3,
	FOUR = 4,
	EIGHT = 5
};

class djrectbutton
{
public:
    djrectbutton();
	djrectbutton(DJBTNTYPE _btntype);
    ~djrectbutton();
    
    void draw();
	void update();
	void onoff();
	void off();

	void settype(DJBTNTYPE _btntype);
    void setloc(int _x,int _y);
	int getsizex();
	int getsizey();

	bool setMouse(int _x,int _y);		//마우스 X좌표값을 가지고 Value와 Degree를 지정해준다.
	
	bool isOn;
private:
    int locX;
    int locY;
    int sizeX;
    int sizeY;
    int round;
    ofColor backColor;
	ofColor CenterColor;
	
	float counter;

	DJBTNTYPE btntype;
    
    void quadraticBezierVertex(float cpx, float cpy, float x, float y, float prevX, float prevY);
    void roundedRect(float x, float y, float w, float h, float r);
};