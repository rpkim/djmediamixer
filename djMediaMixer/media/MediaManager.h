#pragma once

#include "media/soundmanager.h"
#include "media/videomanager.h"

enum MEDIATYPE
{
	AUDIO,
	VIDEO
};

enum KIND
{
	Play,
	Repeat,
	Selector,
	Equalizer,
	SoundPad,
	Volume,
	TurnTable
};


/*
	TYPE	KIND		VALUE		NUM		TEMP01	TEMP02

	audio	Play		0 ~ 1				0 ~ 1
			Repeat		0 ~ 1		0 ~ 3	0 ~	1
			Selector	0 ~ 4				0 ~ 1
			Equalizer	0 ~ 2		0 ~ 2	0 ~ 1
			SoundPad	0 ~ 1		0 ~ 2   0 ~ 2				//NUM : i, TEMP01 : j -> [i][j]
			Volume		0 ~ 2		0 ~ 2
			TurnTable	0 ~ 65535			0 ~ 1
	video   SAME AUDIO

	TEMP01 -> left / right

*/

class MediaManager
{
public:
	MediaManager();
	~MediaManager();

	void ProcessingData(MEDIATYPE type,KIND kind,float value,int num,int temp01,float temp02);
	void ProcessingData(KIND kind,float value,int num,int temp01,float temp02);
	void update();
	void draw();
	void setup();

private:

	//audio processing
	void a_ProcessingPlay(float value,int leftright);
	void a_ProcessingRepeat(float value,int num, int leftright);
	void a_ProcessingSelector(float value,int leftright);
	void a_ProcessingEqualizer(float value, int num, int leftright);
	void a_ProcessingSoundPad(float value,int i,int j);
	void a_ProcessingVolume(float value,int num);

	//audio 
	soundmanager sound;

private:
	private:

	//video processing
	void v_ProcessingPlay(float value,int leftright);
	void v_ProcessingRepeat(float value,int num, int leftright);
	void v_ProcessingSelector(float value,int num,int leftright);
	void v_ProcessingEqualizer(float value,int num, int leftright);
	void v_ProcessingSoundPad(float value,int i, int j);
	void v_ProcessingVolume(float value,int num);

	//video 
	videomanager video;
};