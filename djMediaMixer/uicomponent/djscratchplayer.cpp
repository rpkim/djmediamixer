#include "djscratchplayer.h"

void djscratchplayer::setloc(int _x,int _y)
{
	x = _x;
	y = _y;
}
djscratchplayer::djscratchplayer()
{
	x = 300;
	y = 300;
	bgR = 90;
	centerR = 12;
	g_dgree = 90.0;
	isPlay = false;
}

void djscratchplayer::draw()
{
	ofSetColor(255,0,146);
	ofFill();
	ofCircle(x,y,bgR);

	ofSetColor(252,255,0);
	ofCircle(x,y,centerR);

	ofSetColor(255,255,255);
	//ofLine(x,y,);

	double radian = g_dgree / 180.0 * PI;//3.14159;
	double r = 70;
	double x1 = x + cos(radian) * r;
	double y1 = y + sin(radian) * r;

	//반지름은 20이지
	ofLine(x,y,x1,y1);

	ofSetColor(252,255,0);
	ofCircle(x1,y1,3);

	if(isPlay)
	{
		if(g_dgree >= 450)
		{
			g_dgree = 90;
		}
		for(int i = 0 ; i < 3; i ++)
		{
			g_dgree += 1;
		}
	}
}