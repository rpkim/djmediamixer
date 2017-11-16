#pragma once
#include "ofMain.h"

class djcirclebutton
{
public:
	djcirclebutton();
	~djcirclebutton();

	void draw();					//화면에 그려주는 함수
	void setvalue(float _value);	//값을 지정해 주는 함수.
	float getvalue();				//값을 가져오는 함수.

	void setloc(int _x,int _y);		//위치를 지정해주는 함수
	int getsize();					//circle 크기를 가져오는 함수
	
	void setdegree(double _degree);	//각도를 지정하는 함수
	double getdegree();				//각도를 가져오는 함수

	void setminValue(float _minValue);
	void setmaxValue(float _maxValue);

	bool setMouse(int _x,int _y);		//마우스 x,y좌표값을 가지고 Value와 Degree를 지정해준다.

private:
	int locX;		//중심점 X 좌표
	int locY;		//중심점 Y 좌표
	int size;		//Circle의 지름
	
	float value;	//조절할 때 현재의 값
	float minValue;	//-225도. 즉 최소의 각도로 지정되었을 때의 value( -90도를 기준 -135도)
	float maxValue; //45도. 즉 최대의 각도로 지정되었을 때의 value ( -90도를 기준 +135도)

	ofColor backColor;		//background Color
	ofColor CenterColor;	//Cetner Color

	double degree;	//각도	_ -90도가 중앙에 있을 때의 상태임.
};

#pragma endregion