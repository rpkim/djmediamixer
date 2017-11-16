#include "djsliderbar.h"

#pragma region -- setter,getter
void djsliderbar::settype(bool _isVertical)
{
	isVertical = _isVertical;
	setsize();

	if(isVertical)
	{
		selectlocX = locX;
	}
	else
	{
		selectlocY = locY;
	}
}
bool djsliderbar::setMouse(int _x,int _y)
{
		//유효범위 내
		if(_x >= locX && (_x <= (locX + sizeX)) && _y >= locY && (_y < (locY + sizeY)))
		{
			if(isVertical)	//y
			{
				if(_y <= locY + (select_height/2))
				{
					setvalue(minvalue);
				}
				else if(_y >= locY + sizeY - (select_height/2))
				{
					setvalue(maxvalue);
				}
				else
				{
					float tempvalue = (maxvalue-minvalue) * (_y-locY) / sizeY;
					setvalue(tempvalue);
				}
			}
			else			//x
			{
				if(_x <= locX + (select_width/2))
				{
					setvalue(minvalue);
				}
				else if(_y >= locX + sizeX - (select_width/2))
				{
					setvalue(maxvalue);
				}
				else
				{
					float tempvalue = (maxvalue-minvalue) * (_x-locX) / sizeX;
					setvalue(tempvalue);
				}
			}
			return true;
		}

	return false;
}
void djsliderbar::setsize()
{
	if(isVertical)
	{
	    sizeX = 20;
		sizeY = 240;
		select_width = 16;
		select_height = 40;
	}
	else
	{
	    sizeX = 240;
		sizeY = 20;
		select_width = 40;
		select_height = 16;
	}
}
void djsliderbar::setvalue(float _value)
{
	//유효범위 내
	if(_value >= minvalue && _value <= maxvalue)
	{
		value = _value;
		if(isVertical)
		{
			float s_loc = locY + 2 + ( (sizeY-select_height-4) * _value / (maxvalue - minvalue));

			selectlocY = s_loc;
		}
		else
		{
			float s_loc = locX + 2 + ( (sizeX-select_width-4) * _value / (maxvalue - minvalue));

			selectlocX = s_loc;
		}
	}

}
float djsliderbar::getvalue()
{
	return value;
}
void djsliderbar::setloc(int _x,int _y)
{
	locX = _x;
	locY = _y;

	if(isVertical)
	{
		selectlocX = locX;
	}
	else
	{
		selectlocY = locY;
	}
}
void djsliderbar::setmaxvalue(float _value)
{
	maxvalue = _value;
}
void djsliderbar::setminvalue(float _value)
{
	minvalue = _value;
}
#pragma endregion

djsliderbar::djsliderbar()
{
	isVertical = false;
	locX = locY = 100;
	if(isVertical)
	{
		selectlocX = locX;
	}
	else
	{
		selectlocY = locY;
	}

    backColor.set(192,0,255);
    round = 15;

	setsize();
}
djsliderbar::djsliderbar(bool _isVertical)
{
	djsliderbar();
	
	locX = locY = 100;

    backColor.set(192,0,255);
    round = 15;

	isVertical = _isVertical;
	setsize();
}



void djsliderbar::draw()
{
	ofEnableSmoothing();   
    ofFill();
	ofSetColor(backColor);
    
	roundedRect(locX,locY,sizeX,sizeY,round);
	ofSetColor(255,255,255);

	if(isVertical)
	{
		roundedRect(selectlocX+2,selectlocY,select_width,select_height,round-5);
	}
	else
	{
		roundedRect(selectlocX,selectlocY+2,select_width,select_height,round-5);
	}


}


void djsliderbar::roundedRect(float x, float y, float w, float h, float r) {  
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
void djsliderbar::quadraticBezierVertex(float cpx, float cpy, float x, float y, float prevX, float prevY) {  
    float cp1x = prevX + 2.0/3.0*(cpx - prevX);  
    float cp1y = prevY + 2.0/3.0*(cpy - prevY);  
    float cp2x = cp1x + (x - prevX)/3.0;  
    float cp2y = cp1y + (y - prevY)/3.0;  
    
    // finally call cubic Bezier curve function  
    ofBezierVertex(cp1x, cp1y, cp2x, cp2y, x, y);  
}; 


