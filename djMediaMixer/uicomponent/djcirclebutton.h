#pragma once
#include "ofMain.h"

class djcirclebutton
{
public:
	djcirclebutton();
	~djcirclebutton();

	void draw();					//ȭ�鿡 �׷��ִ� �Լ�
	void setvalue(float _value);	//���� ������ �ִ� �Լ�.
	float getvalue();				//���� �������� �Լ�.

	void setloc(int _x,int _y);		//��ġ�� �������ִ� �Լ�
	int getsize();					//circle ũ�⸦ �������� �Լ�
	
	void setdegree(double _degree);	//������ �����ϴ� �Լ�
	double getdegree();				//������ �������� �Լ�

	void setminValue(float _minValue);
	void setmaxValue(float _maxValue);

	bool setMouse(int _x,int _y);		//���콺 x,y��ǥ���� ������ Value�� Degree�� �������ش�.

private:
	int locX;		//�߽��� X ��ǥ
	int locY;		//�߽��� Y ��ǥ
	int size;		//Circle�� ����
	
	float value;	//������ �� ������ ��
	float minValue;	//-225��. �� �ּ��� ������ �����Ǿ��� ���� value( -90���� ���� -135��)
	float maxValue; //45��. �� �ִ��� ������ �����Ǿ��� ���� value ( -90���� ���� +135��)

	ofColor backColor;		//background Color
	ofColor CenterColor;	//Cetner Color

	double degree;	//����	_ -90���� �߾ӿ� ���� ���� ������.
};

#pragma endregion