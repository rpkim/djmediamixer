#pragma once

#include "ofMain.h"
#include "ofxJello.h"

#include "media/mediamanager.h"
#include "virtual_dj_player.h"
#include "serial/djserial.h"

enum VideoType
{
	VirtualDJ,
	HardwareDJ
};

class djMediaMixerApp : public ofBaseApp{
public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button); 
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

private:
	VideoType type;


private:
	djserial serial;
	MediaManager media;
	virtual_dj_player virtualDJ;	

	ofxJello jello;
	ofxJelloBody groundBody;
	ofxJelloBody jellobody;


};
