#pragma once

#include "videomanager.h"

videomanager::videomanager()
{
	for(int i = 0 ; i < 5 ; i ++)
	{
		IsOnSource[i] = false;
	}

	IsOnSource[0] = true;

	rotX = rotY = rotZ = 0;
}

void videomanager::setRotateX(float x)
{
	rotX = x;
}
void videomanager::setRotateY(float y)
{
	rotY = y;
}
void videomanager::setRotateZ(float z)
{
	rotZ = z;
}

videomanager::~videomanager()
{
	//myGrabber.close();
}
void videomanager::update()
{
	if(IsOnSource[0])
	{
		//myGrabber.update();
	}
}
void videomanager::setSource(int i, bool ison)
{
	IsOnSource[i] = ison;
}
void videomanager::setup()
{
	//myGrabber.initGrabber(320,240);
}
void videomanager::draw()
{
	if(IsOnSource[0])
	{
		//draw_01();
	}

}
void videomanager::draw_01()
{
	unsigned char * pixels = myGrabber.getPixels();
	
	for (int i = 0; i < myGrabber.width; i = i + 4){
		for (int j = 0; j < myGrabber.height; j = j + 4){
			
			int red		= pixels[ (j *  myGrabber.width + i)*3    ];
			int green	= pixels[ (j *  myGrabber.width + i)*3 + 1];
			int blue	= pixels[ (j *  myGrabber.width + i)*3 + 2];
			
			float brightness = ((red + green + blue) / 3.0) / 255.0;
			
			ofSetColor(255*brightness,255,255*brightness);
      
			ofPushMatrix();
			ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
        
			ofPushMatrix();

			ofRotateX(rotX);
			ofRotateY(rotY);
			ofRotateZ(rotZ);

			
			ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2, -250*brightness);

			ofCircle(i,j,1.5);
            
			ofPopMatrix();
      
		ofPopMatrix();	
		}
	}
}
