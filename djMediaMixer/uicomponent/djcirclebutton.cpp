#include "djcirclebutton.h"

djcirclebutton::djcirclebutton()
{
	degree = -90;
	locX = locY = 100;
    size = 40;
    backColor.set(0,132,255);
	CenterColor.set(252,255,0);
}
djcirclebutton::~djcirclebutton()
{
}

#pragma region -- getter&setter
void djcirclebutton::setloc(int _x,int _y)
{
	locX = _x;
	locY = _y;
}
int djcirclebutton::getsize()
{
	return size;
}
void djcirclebutton::setdegree(double _degree)
{
	if(_degree >= -225 && _degree <= 45)
	{
		degree = _degree;

		int howfar = degree + 225;

		value = (maxValue - minValue) / 270 * howfar;
	}
}
void djcirclebutton::setminValue(float _minValue)
{
	minValue = _minValue;
}
void djcirclebutton::setmaxValue(float _maxValue)
{
	maxValue = _maxValue;
}

double djcirclebutton::getdegree()
{
	return degree;
}
void djcirclebutton::setvalue(float _value)
{
	if(_value >= minValue && _value <= maxValue)
	{
		value = _value;
		//270도

		float oneDegreeValue = (maxValue - minValue) / 270;
		

		degree = -225 + value/oneDegreeValue;
	}
}
float djcirclebutton::getvalue()
{
	return value;
}
bool djcirclebutton::setMouse(int _x,int _y)
{
	//locX is minValue
	//locX + size is maxValue
	
	double xminwidth = locX - (size/2);
	double xmaxwidth = locX + (size/2);

	if(_x >= locX-(size/2) && _x <= locX +(size/2))
	{
		if(_y <= locY + (size/2) && _y >= locY - (size/2))
		{
			
			double radian = atan((double)((double)abs((locY - _y)) / (double)abs((locX - _x))));

			double deg = radian * 180 / PI;

			if(_y < locY)
			{
				if(_x < locX)				//1사분면
				{
					deg = ((90 - deg) + 90)* -1;
				}
				else						//2사분면
				{
					deg = -90 + (90 - deg);
				}
			}
			else
			{
				if(_x < locX)				//3사분면
				{
					deg = (deg + 180)* -1;
				}
				else						//4사분면
				{
				}
			}

	
			//double howfar = _x - (locX-(size/2));

			//double tempDegree = - 225 + (270 / (double)(locX + size/2) * howfar);
			setdegree(deg);
		}
		return true;
	}
	return false;
}
#pragma endregion

void djcirclebutton::draw()
{
	ofFill();
    
	//background draw
	ofSetColor(backColor);
	ofCircle(locX,locY,size/2);

	//center draw
	ofSetColor(CenterColor);
	ofCircle(locX,locY,4);

	//line draw
	ofSetColor(255,255,255);

//	ofLine(locX,locY,locX,locY-18);
//	ofLine(locX,locY,locX,locY-18);
	
	double radian = degree / 180.0 * PI;//3.14159;

	double x1 = locX;
	double y1 = locY;
	double r = (size / 2) - 2;
	double x2 = locX + cos(radian) * r;
	double y2 = locY + sin(radian) * r;

	//반지름은 20이지.
	ofLine(x1,y1,x2,y2);
}
