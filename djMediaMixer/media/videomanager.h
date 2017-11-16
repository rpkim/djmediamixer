#pragma once

#include "ofMain.h"

class videomanager
{
	public:
		videomanager();
		~videomanager();
		void setup();
		void update();
		void draw();
		
		void setSource(int i, bool ison);


		void setRotateX(float x);
		void setRotateY(float y);
		void setRotateZ(float z);

	private:
		ofVideoGrabber   myGrabber;
		void draw_01();

		bool IsOnSource[5];

		float rotX;
		float rotY;
		float rotZ;

};
