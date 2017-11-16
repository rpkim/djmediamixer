#pragma once
#include "ofMain.h"

#define PLAYERCOUNT 5

class soundmanager
{
public:
	soundmanager();
	~soundmanager();

	void change_song(int leftright,int num);

	void setVolume(int leftright,float vol);
	void playSound(int leftright);
	void playSoundPad(int i,int j);
	void pauseSound(int leftright);
	
	void setSpeed(int leftright,float speed);
	void setRatio(float _ratio);
	void setRepeat(int leftright,int kind);
	void stopRepeat(int leftright);
	
	float RepeatInitTime[2];
	float RepeatEndTime[2];
	void update();


private:
	//0 : left, 1 : right
	bool IsRepeat[2];

	//0 : left, 1 : right
	int play_num[2];	

	//left right volume ratio
	float ratio;

	//left volume
	float left_volume;

	//right volume
	float right_volume;
	
	//left player _ 0,1,2,3,4
	ofSoundPlayer player_left[PLAYERCOUNT];

	//right player _ 0,1,2,3,4
	ofSoundPlayer player_right[PLAYERCOUNT];

	//soundPad _ 9.
	ofSoundPlayer soundpad[3][3];

private:
	void loadsong();
};