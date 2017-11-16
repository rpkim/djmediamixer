#pragma once

//UI Component
#include "uicomponent/djcirclebutton.h"
#include "uicomponent/djrectbutton.h"
#include "uicomponent/djscratchplayer.h"
#include "uicomponent/djsliderbar.h"

#include "media/MediaManager.h"

#include <stack>

struct int2
{
	int data;
	int data1;
};

class virtual_dj_player
{
	public:
		virtual_dj_player();
		~virtual_dj_player();
		void draw();
		void setup();
		void clean_repeat(int leftright);
		
		void mouseDragged(int x, int y, int button,MediaManager* media);
		void mousePressed(int x, int y, int button,MediaManager* media);
		void mouseReleased(int x, int y, int button,MediaManager* media);
			
	private:
		djrectbutton selector[16];
		djcirclebutton left_equalizer[3];
		djcirclebutton right_equalizer[3];
		djrectbutton soundpad[4][4];
		djsliderbar left_volume;
		djsliderbar right_volume;
		djsliderbar center_volume;
		djscratchplayer left_scratchplayer;
		djscratchplayer right_scratchplayer;
		djrectbutton left_repeat[4];
		djrectbutton right_repeat[4];
		djrectbutton left_playpause;
		djrectbutton right_playpause;

		ofTrueTypeFont  myriadProBold;

		bool soundpad_pressed;

private:
	void component_init();
		
};
