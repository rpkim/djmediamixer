#include "djrectbutton.h"

djrectbutton::djrectbutton()
{
    locX = locY = 100;
    sizeX = sizeY = 50;
    backColor.set(0,132,255);
    round = 10;
	isOn = false;
	CenterColor.set(252,255,0);
	btntype = NORMAL;
}
djrectbutton::djrectbutton(DJBTNTYPE _btntype)
{
	djrectbutton();
	btntype = _btntype;
}
bool djrectbutton::setMouse(int _x,int _y)
{
	if(_x >= locX && _x <= locX+sizeX)
	{
		if(_y >= locY && _y <= locY + sizeY)
		{
			onoff();
			return true;
		}
	}
	return false;
}


void djrectbutton::settype(DJBTNTYPE _btntype)
{
	btntype = _btntype;
}
int djrectbutton::getsizex()
{
	return sizeX;
}
int djrectbutton::getsizey()
{
	return sizeY;
}
void djrectbutton::setloc(int _x,int _y)
{
	locX = _x;
	locY = _y;
}

djrectbutton::~djrectbutton()
{
    
}

void djrectbutton::update()
{
	counter = counter + 0.033f;
	if(counter > 0.033f * 100)
	{
		counter = 0;
	}
	
}
void djrectbutton::draw()
{
    ofEnableSmoothing();   
    ofFill();
    ofSetColor(backColor);
    
    roundedRect(locX,locY,sizeX,sizeY,round);
	
	// 밑쪽 ( 점. 1 ~ 4 )
	if(btntype == ONE || btntype == TWO || btntype == FOUR)
	{
		//deco
	    ofSetColor(255,255,255);
		ofLine(locX+5,locY+(sizeY/6*4),locX+sizeX-5,locY+(sizeY/6*4));
	}

	if(btntype == EIGHT)
	{
		//deco
	    ofSetColor(255,255,255);
		ofLine(locX+5,locY+(sizeY/6*4) - 10,locX+sizeX-5,locY+(sizeY/6*4) - 10);
	}

	// ㅣ 가운데
	if(btntype == TOGGLE)
	{
		//deco
	    ofSetColor(255,255,255);
		ofLine(locX + (sizeX/2),locY+5,locX + (sizeX/2),locY+sizeY-5);
	}

	// 점 하나
	if(btntype == ONE)
	{
		//bottom
		ofSetColor(CenterColor);
		ofCircle(locX + sizeX/2, locY + sizeY/5*4,3);
	}
	else if(btntype == TWO)
	{
		ofSetColor(CenterColor);
		// 점 둘
		ofCircle(locX + sizeX/5*2, locY + sizeY/5*4,3);
		ofCircle(locX + sizeX/5*3, locY + sizeY/5*4,3);
	}
	else if(btntype == FOUR)
	{
		ofSetColor(CenterColor);
		// 점 넷
		ofCircle(locX + sizeX/5*1, locY + sizeY/5*4,3);
		ofCircle(locX + sizeX/5*2, locY + sizeY/5*4,3);
		ofCircle(locX + sizeX/5*3, locY + sizeY/5*4,3);
		ofCircle(locX + sizeX/5*4, locY + sizeY/5*4,3);
	}
	else if(btntype == EIGHT)
	{
		ofSetColor(CenterColor);
		// 점 여덟
		ofCircle(locX + sizeX/5*1, locY + sizeY/5*4,3);
		ofCircle(locX + sizeX/5*2, locY + sizeY/5*4,3);
		ofCircle(locX + sizeX/5*3, locY + sizeY/5*4,3);
		ofCircle(locX + sizeX/5*4, locY + sizeY/5*4,3);

		ofCircle(locX + sizeX/5*1, locY + sizeY/5*4 - 8,3);
		ofCircle(locX + sizeX/5*2, locY + sizeY/5*4 - 8,3);
		ofCircle(locX + sizeX/5*3, locY + sizeY/5*4 - 8,3);
		ofCircle(locX + sizeX/5*4, locY + sizeY/5*4 - 8,3);
	}
	//draw yellow circle in center.
	if(isOn)
	{
		ofFill();
		ofSetColor(CenterColor);

		if(btntype == NORMAL)
		{		
			//가운데 점
			ofCircle(locX + sizeX/2, locY + sizeY/2,4); //2 + 2 * sin(counter));
		}
		else if(btntype == ONE || btntype == TWO || btntype == FOUR || btntype == EIGHT)
		{
			//위에 점
			ofCircle(locX + sizeX/2, locY + sizeY/2 - 12,4);
		}
		else if(btntype == TOGGLE)
		{
			//왼쪽 점
			ofCircle(locX + sizeX/2 - 12, locY + sizeY/2, 4);
		}
	}
	else
	{
		ofFill();
		ofSetColor(CenterColor);

		if(btntype == TOGGLE)
		{
			//오른쪽 점
			ofCircle(locX + sizeX/2 + 12, locY + sizeY/2, 4);
		}
	}
}
void djrectbutton::onoff()
{
	isOn = !isOn;
}
void djrectbutton::off()
{
	isOn = false;
}
void djrectbutton::roundedRect(float x, float y, float w, float h, float r) {  
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();  
    ofVertex(x+r, y);  
    ofVertex(x+w-r, y);  
    quadraticBezierVertex(x+w, y, x+w, y+r, x+w-r, y);  
    ofVertex(x+w, y+h-r);  
    quadraticBezierVertex(x+w, y+h, x+w-r, y+h, x+w, y+h-r);  
    ofVertex(x+r, y+h);  
    quadraticBezierVertex(x, y+h, x, y+h-r, x+r, y+h);  
    ofVertex(x, y+r);  
    quadraticBezierVertex(x, y, x+r, y, x, y+r);  
    ofEndShape();  
}  
void djrectbutton::quadraticBezierVertex(float cpx, float cpy, float x, float y, float prevX, float prevY) {  
    float cp1x = prevX + 2.0/3.0*(cpx - prevX);  
    float cp1y = prevY + 2.0/3.0*(cpy - prevY);  
    float cp2x = cp1x + (x - prevX)/3.0;  
    float cp2y = cp1y + (y - prevY)/3.0;  
    
    // finally call cubic Bezier curve function  
    ofBezierVertex(cp1x, cp1y, cp2x, cp2y, x, y);  
}; 
