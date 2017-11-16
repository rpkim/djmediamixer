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

	float getvalue();				//���� �������� �Լ�
	void setvalue(float _value);	//���� ������ �ִ� �Լ�

	void draw();

	void setloc(int _x,int _y);		//��ġ�� �������ִ� �Լ�
	
	void settype(bool _isVertical);	//���θ��,���θ�带 �������ִ� �Լ�

	void setmaxvalue(float _value);	//�ִ밪�� �־���
	void setminvalue(float _value);	//�ּҰ��� �־���

	bool setMouse(int _x,int _y);		//���콺 X��ǥ���� ������ Value�� Degree�� �������ش�.

private:

	float maxvalue;
	float minvalue;

	int locX;			//���� �����ڸ� ������ X��ǥ
	int locY;			//���� �����ڸ� ������ Y��ǥ

	int selectlocX;		//���� �����̴� X��ġ
	int selectlocY;		//���� �����̴� Y��ġ

	int sizeX;			//�����̴� width
	int sizeY;			//�����̴� height

	bool isVertical;	//���θ������ ���θ������

	int round;			

	float value;		//��

	int select_width;	//���õǴ� �����̴��� ���� ����
	int select_height;	//���õǴ� �����̴��� ���� ����

	ofColor backColor;

	void setsize();

    void quadraticBezierVertex(float cpx, float cpy, float x, float y, float prevX, float prevY);
    void roundedRect(float x, float y, float w, float h, float r);
};

