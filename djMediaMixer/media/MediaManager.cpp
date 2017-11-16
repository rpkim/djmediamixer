#include "MediaManager.h"


MediaManager::MediaManager()
{
	
}
MediaManager::~MediaManager()
{

}
void MediaManager::ProcessingData(MEDIATYPE type,KIND kind,float value,int num,int temp01,float temp02)
{
	if(type == AUDIO)	//audio input
	{
		if(kind == Play)
		{
			a_ProcessingPlay(value,temp01);
		}
		else if(kind == Repeat)
		{
			a_ProcessingRepeat(value,num,temp01);
		}
		else if(kind == Selector)
		{
			a_ProcessingSelector(value,temp01);
		}
		else if(kind == Equalizer)
		{
			a_ProcessingEqualizer(value,num,temp01);
		}
		else if(kind == SoundPad)
		{
			a_ProcessingSoundPad(value,num,temp01);
		}
		else if(kind == Volume)
		{
			a_ProcessingVolume(value,num);
		}
	}
	else if(type == VIDEO)	//video input
	{
		if(kind == Play)
		{
			v_ProcessingPlay(value,temp01);
		}
		else if(kind == Repeat)
		{
			v_ProcessingRepeat(value,num,temp01);
		}
		else if(kind == Selector)
		{
			v_ProcessingSelector(value,num,temp01);
		}
		else if(kind == Equalizer)
		{
			v_ProcessingEqualizer(value,num,temp01);
		}
		else if(kind == SoundPad)
		{
			v_ProcessingSoundPad(value,num,temp01);
		}
		else if(kind == Volume)
		{
			v_ProcessingVolume(value,num);
		}
	}
}
void MediaManager::ProcessingData(KIND kind,float value,int num,int temp01,float temp02)
{
	if(kind == Play)
	{
		a_ProcessingPlay(value,temp01);
		v_ProcessingPlay(value,temp01);
	}
	else if(kind == Repeat)
	{
		a_ProcessingRepeat(value,num,temp01);
		v_ProcessingRepeat(value,num,temp01);
	}
	else if(kind == Selector)
	{
		//value num, temp01 -> ¿Ã∞« ª©∞Ì
		//a_ProcessingSelector(value,temp01);
		v_ProcessingSelector(value,num,temp01);
	}
	else if(kind == Equalizer)
	{
		a_ProcessingEqualizer(value,num,temp01);
		v_ProcessingEqualizer(value,num,temp01);
	}
	else if(kind == SoundPad)
	{
		a_ProcessingSoundPad(value,num,temp01);
		v_ProcessingSoundPad(value,num,temp01);
	}
	else if(kind == Volume)
	{
		a_ProcessingVolume(value,num);
		v_ProcessingVolume(value,num);
	}
}

//audio processing
void MediaManager::a_ProcessingPlay(float value,int leftright)
{
	if(value == 0)
	{
		sound.pauseSound(leftright);
	}
	else
	{
		sound.playSound(leftright);
	}
}
void MediaManager::a_ProcessingRepeat(float value,int num, int leftright)
{
	if(value == 1)
	{
		sound.setRepeat(leftright,num);
	}
	else if(value == 0)
	{
		sound.stopRepeat(leftright);
	}
}
void MediaManager::a_ProcessingSelector(float value,int leftright)
{
	sound.change_song(leftright,value);
}
void MediaManager::a_ProcessingEqualizer(float value, int num, int leftright)
{
	if(num == 0)
	{
		sound.setSpeed(leftright,value);
	}

}
void MediaManager::a_ProcessingSoundPad(float value,int i, int j)
{
	sound.playSoundPad(i,j);
}
void MediaManager::a_ProcessingVolume(float value,int num)
{
	if(num == 2)
	{
		sound.setRatio(value);
	}
	else
	{
		sound.setVolume(num,value);
	}
}

void MediaManager::v_ProcessingPlay(float value,int leftright)
{
}
void MediaManager::v_ProcessingRepeat(float value,int num, int leftright)
{
}
void MediaManager::v_ProcessingSelector(float value,int num, int leftright)
{
	video.setSource(num,(bool)value);
}
void MediaManager::v_ProcessingEqualizer(float value, int num, int leftright)
{
}
void MediaManager::v_ProcessingSoundPad(float value,int i, int j)
{
}
void MediaManager::v_ProcessingVolume(float value,int num)
{
	if(num == 0)
	{
		video.setRotateX(value*360);
	}
	else if(num == 1)
	{
		video.setRotateY(value*360);
	}
	else if(num == 2)
	{
		video.setRotateZ(value*360);
	}
}
void MediaManager::setup()
{
	video.setup();
}
void MediaManager::update()
{
	sound.update();
	video.update();
}
void MediaManager::draw()
{
	video.draw();
}