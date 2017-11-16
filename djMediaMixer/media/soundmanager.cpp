#include "soundmanager.h"

soundmanager::soundmanager()
{
	ratio= 0.5;
	
	IsRepeat[0] = false;
	IsRepeat[1] = false;

	//track number is 1
	play_num[0] = 0;
	play_num[1] = 0;

	//volume 
	setVolume(0,1);
	setVolume(1,1);

	//music load
	loadsong();
}
void soundmanager::loadsong()
{
	player_left[0].loadSound("L1_LMFAO & Steve Aoki_Livin' My Love.mp3");
	player_left[1].loadSound("L2_Albert Kick_Camper (Feat. Jason Rene) (Radio Mix).mp3");
	player_left[2].loadSound("L3_Big Sean_Dance (A$$) Remix (Feat. Nicki Minaj).mp3");
	player_left[3].loadSound("L4_Gym Class Heroes_Stereo Hearts (Feat. Adam Levine Of Maroon 5).mp3");
	player_left[4].loadSound("L5_Taio Cruz_Hangover (Feat. Flo Rida).mp3");

	player_right[0].loadSound("R1_LMFAO_Sexy And I Know It (Mord Fustang).mp3");
	player_right[1].loadSound("R2_Afrojack_Take Over Control (Feat. Eva Simons)(Radio Edit).mp3");
	player_right[2].loadSound("R3_Yanou_King Of My Castle (Radio Mix).mp3");
	player_right[3].loadSound("R4_QUAGUA_¹ø³úÀÇ Dance.mp3");
	player_right[4].loadSound("R5_Justice_Helix.mp3");

	soundpad[0][0].loadSound("01_Ah Yeah (Run DMC).MP3");
	soundpad[0][1].loadSound("02_Asshole.MP3");
	soundpad[0][2].loadSound("03_1,2,3,4.MP3");
	soundpad[1][0].loadSound("04_Ah (JD).MP3");
	soundpad[1][1].loadSound("05_Ahahah (Jay Z).MP3");
	soundpad[1][2].loadSound("06_Aha (Timbaland).MP3");
	soundpad[2][0].loadSound("07_Ahh (Female).MP3");
	soundpad[2][1].loadSound("08_Ain't Nobody Do It Like We Do.MP3");
	soundpad[2][2].loadSound("09_Ain't Number Toody Frutty Get Up The Floor If You Got That B.MP3");

	for(int i = 0 ; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			soundpad[i][j].setMultiPlay(true);
			soundpad[i][j].setLoop(false);
		}
	}

	for(int i = 0 ; i < PLAYERCOUNT; i++)
	{
		player_left[i].setMultiPlay(true);
		player_left[i].setLoop(true);
		player_right[i].setMultiPlay(true);
		player_right[i].setLoop(true);
	}
}
void soundmanager::setVolume(int i,float vol)
{
	if(i == 0)
	{
		left_volume = vol;
		player_left[play_num[0]].setVolume(left_volume * (1 - ratio));
	}
	else if(i == 1)
	{
		right_volume = vol;
		player_right[play_num[1]].setVolume(right_volume * ratio);
	}
}
soundmanager::~soundmanager()
{
}
void soundmanager::playSoundPad(int i,int j)
{
	soundpad[i][j].play();
}
void soundmanager::playSound(int i)
{
	if(i == 0)
	{
		if(!player_left[play_num[0]].getIsPlaying())
		{
			player_left[play_num[0]].play();
		}
		else
		{
			player_left[play_num[0]].setPaused(false);
		}
	}
	else if(i == 1)
	{
		if(!player_right[play_num[1]].getIsPlaying())
		{
			player_right[play_num[1]].play();
		}
		else
		{
			player_right[play_num[1]].setPaused(false);
		}
	}
}
void soundmanager::pauseSound(int i)
{
	if(i == 0)
	{
		player_left[play_num[0]].setPaused(true);
	}
	else if(i == 1)
	{
		player_right[play_num[1]].setPaused(true);
	}
}
void soundmanager::stopRepeat(int i)
{
	if(i == 0)
	{
		IsRepeat[0] = false;
	}
	else if(i == 1)
	{
		IsRepeat[1] = false;
	}
}
void soundmanager::setRepeat(int i,int kind)
{
	float time;
	if(kind == 0)
	{
		time = 0.001;
	}
	else if(kind == 1)
	{
		time = 0.002;
	}
	else if(kind == 2)
	{
		time = 0.003;
	}
	else if(kind == 3)
	{
		time = 0.004;
	}

	if(i == 0)
	{
		IsRepeat[0] = true;
		RepeatInitTime[0] = player_left[play_num[0]].getPosition();
		RepeatEndTime[0] = RepeatInitTime[0] + time;
	}
	else if(i == 1)
	{
		IsRepeat[1] = true;
		RepeatInitTime[1] = player_right[play_num[1]].getPosition();
		RepeatEndTime[1] = RepeatInitTime[1] + time;
	}
}
void soundmanager::setRatio(float _ratio)
{
	ratio = _ratio;

	player_left[play_num[0]].setVolume(left_volume * (1-ratio));
	player_right[play_num[1]].setVolume(right_volume * ratio);
}
void soundmanager::update()
{
	if(IsRepeat[0])
	{
		//
		float position = player_left[play_num[0]].getPosition();
		if(position >= RepeatEndTime[0])
		{
			player_left[play_num[0]].setPosition(RepeatInitTime[0]);
		}
	}
	
	if(IsRepeat[1])
	{
		//
		float position = player_right[play_num[1]].getPosition();
		if(position >= RepeatEndTime[1])
		{
			player_right[play_num[1]].setPosition(RepeatInitTime[1]);
		}
	}
}
void soundmanager::setSpeed(int i,float speed)
{
	if(i == 0)
	{
		player_left[play_num[0]].setSpeed(speed);
	}
	else if(i == 1)
	{
		player_right[play_num[1]].setSpeed(speed);
	}
	
}
void soundmanager::change_song(int leftright,int num)
{
	int before_num = 0;
	if(leftright == 0)
	{
		before_num = play_num[0];
		play_num[0] = num;

		player_left[play_num[0]].setVolume(left_volume);
		
		player_left[before_num].stop();
		player_left[play_num[0]].play();

		IsRepeat[0] = false;
	}
	else if(leftright == 1)
	{
		before_num = play_num[1];
		play_num[1] = num;

		player_right[play_num[1]].setVolume(right_volume);
		player_right[before_num].stop();
		player_right[play_num[1]].play();

		IsRepeat[1] = false;
	}
}