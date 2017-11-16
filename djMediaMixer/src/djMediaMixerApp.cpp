#include "djMediaMixerApp.h"
#include "math.h"


//--------------------------------------------------------------
void djMediaMixerApp::setup(){

	//type = VirtualDJ;
	type = HardwareDJ;

	virtualDJ.setup();
	media.setup();
	serial.media = &media;
	serial.setup();

	ofSetWindowTitle("MediaMixer");

	ofSetCircleResolution(100);
	ofSetFrameRate(120);

	/*
	ofPolyline ground;
	ground.addVertex(ofPoint(0,0));
	ground.addVertex(ofPoint(500,0));
	ground.addVertex(ofPoint(500,5));
	ground.addVertex(ofPoint(0,5));

	groundBody.createBody(ground, 1, ofPoint(ofGetWidth()*.25, ofGetHeight()*.25));

	
	jello.addBody(&groundBody);
	
	jello.setGravity(ofPoint(ofGetWidth()*.25, ofGetHeight()*.25));
	
	
	ofPolyline jay;
	jay.addVertex(ofPoint(0,0));
	jay.addVertex(ofPoint(100,0));
	jay.addVertex(ofPoint(100,100));
	jay.addVertex(ofPoint(0,100));

	jellobody.createBody(jay, 10 , ofPoint(ofGetWidth()*.25, 10),0.0f,ofPoint(1,1),true);

	jello.addBody(&jellobody);

	*/

}

//--------------------------------------------------------------
void djMediaMixerApp::update()
{
	media.update();
	serial.update();

	//jello.update();
}
//--------------------------------------------------------------
void djMediaMixerApp::draw()
{
	if(type == VirtualDJ)
	{
		ofBackground(255,255,255);
		virtualDJ.draw();
	}
	else
	{
		ofBackground(0,0,0);
		media.draw();
	//	jello.draw();
	}
	
	
}

//--------------------------------------------------------------
void djMediaMixerApp::keyPressed(int key){

	if(key == '1')
	{
		media.ProcessingData(AUDIO,Selector,0,-999,0,-999);
	}
	else if(key == '2')
	{
		media.ProcessingData(AUDIO,Selector,1,-999,0,-999);
	}
	else if(key == '3')
	{
		media.ProcessingData(AUDIO,Selector,2,-999,0,-999);
	}
	else if(key == '4')
	{
		media.ProcessingData(AUDIO,Selector,3,-999,0,-999);
	}
	else if(key == '5')
	{
		media.ProcessingData(AUDIO,Selector,4,-999,0,-999);
	}
	else if(key == '6')
	{
		media.ProcessingData(AUDIO,Selector,0,-999,1,-999);
	}
	else if(key == '7')
	{
		media.ProcessingData(AUDIO,Selector,1,-999,1,-999);
	}
	else if(key == '8')
	{
		media.ProcessingData(AUDIO,Selector,2,-999,1,-999);
	}
	else if(key == '9')
	{
		media.ProcessingData(AUDIO,Selector,3,-999,1,-999);
	}
	else if(key == '0')
	{
		media.ProcessingData(AUDIO,Selector,4,-999,1,-999);
	}    

	if(key == 'm' || key == 'M')
	{
		if(type == VirtualDJ)
		{
			type = HardwareDJ;
		}
		else
		{
			type = VirtualDJ;
		}
	}

	if(key == '1' || key == '2' || key == '3' || key == '4')
	{
		if(type == VirtualDJ)
		{
			virtualDJ.clean_repeat(0);
		}
	}
	else if(key == '5' || key == '6' || key == '7' || key == '8')
	{
		if(type == VirtualDJ)
		{
			virtualDJ.clean_repeat(1);
		}
	}
	
}
//--------------------------------------------------------------
void djMediaMixerApp::keyReleased(int key){

}
//--------------------------------------------------------------
void djMediaMixerApp::mouseMoved(int x, int y )
{
}
//--------------------------------------------------------------
void djMediaMixerApp::mouseDragged(int x, int y, int button)
{
	if(type == VirtualDJ)
	{
		virtualDJ.mouseDragged(x,y,button,&media);
	}
}
//--------------------------------------------------------------
void djMediaMixerApp::mousePressed(int x, int y, int button)
{
	if(type == VirtualDJ)
	{
		virtualDJ.mousePressed(x,y,button,&media);
	}
}

//--------------------------------------------------------------
void djMediaMixerApp::mouseReleased(int x, int y, int button)
{
	if(type == VirtualDJ)
	{
		virtualDJ.mouseReleased(x,y,button,&media);
	}
}

//--------------------------------------------------------------
void djMediaMixerApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void djMediaMixerApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void djMediaMixerApp::dragEvent(ofDragInfo dragInfo){ 

}