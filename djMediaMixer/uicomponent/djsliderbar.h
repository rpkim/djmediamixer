#pragma once
#include "ofMain.h"

/**
dj sliderbar UI Component
*/
class djsliderbar
{
public:
	djsliderbar();
	djsliderbar(bool _isVertical);

	float getvalue();				//값을 가져오는 함수
	void setvalue(float _value);	//값을 지정해 주는 함수

	void draw();

	void setloc(int _x,int _y);		//위치를 지정해주는 함수
	
	void settype(bool _isVertical);	//가로모드,세로모드를 지정해주는 함수

	void setmaxvalue(float _value);	//최대값을 넣어줌
	void setminvalue(float _value);	//최소값을 넣어줌

	bool setMouse(int _x,int _y);		//마우스 X좌표값을 가지고 Value와 Degree를 지정해준다.

private:

	float maxvalue;
	float minvalue;

	int locX;			//왼쪽 가장자리 시작점 X좌표
	int locY;			//왼쪽 가장자리 시작점 Y좌표

	int selectlocX;		//선택 슬라이더 X위치
	int selectlocY;		//선택 슬라이더 Y위치

	int sizeX;			//슬라이더 width
	int sizeY;			//슬라이더 height

	bool isVertical;	//가로모드인지 세로모드인지

	int round;			

	float value;		//값

	int select_width;	//선택되는 슬라이더의 가로 길이
	int select_height;	//선택되는 슬라이더의 세로 길이

	ofColor backColor;

	void setsize();

    void quadraticBezierVertex(float cpx, float cpy, float x, float y, float prevX, float prevY);
    void roundedRect(float x, float y, float w, float h, float r);
};

