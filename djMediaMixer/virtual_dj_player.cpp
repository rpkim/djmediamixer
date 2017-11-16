#pragma once
#include "virtual_dj_player.h"

void virtual_dj_player::component_init()
{
		//set button
	for(int i = 0 ; i < 16; i ++)
	{
		selector[i].settype(NORMAL);
		int j = i*selector[i].getsizex();
		if(i != 0)
		{
			j = j+4*i;
		}
		selector[i].setloc(100 + j ,100); 
	}

	for(int i = 0 ; i < 3; i++)
	{
		int j = i*left_equalizer[i].getsize();
		left_equalizer[i].setloc(361 + j+4*i,225);
		left_equalizer[i].setminValue(0);
		left_equalizer[i].setmaxValue(2);

	}
	for(int i = 0 ; i < 3; i++)
	{
		int j = i*right_equalizer[i].getsize();
		right_equalizer[i].setloc(567 + j+4*i,225);
		right_equalizer[i].setminValue(0);
		right_equalizer[i].setmaxValue(2);

	}

	left_volume.settype(true);
	right_volume.settype(true);
	center_volume.settype(false);

	//164.282
	left_volume.setloc(164,282);
	right_volume.setloc(844,282);
	center_volume.setloc(382,538);
	//382.538

	left_scratchplayer.setloc(300,436);
	right_scratchplayer.setloc(730,436);

	int tempLocX = 410;
	int tempLocY = 285;
	for(int i = 0 ; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
				soundpad[i][j].setloc(410 + i * 52,285 + j * 52);
		}
	}

	left_repeat[0].setloc(55,535);
	left_repeat[1].setloc(55+left_repeat[0].getsizex() + 2,535);
	left_repeat[2].setloc(55,535 + left_repeat[0].getsizey() + 2);
	left_repeat[3].setloc(55+left_repeat[0].getsizex() + 2,535 + left_repeat[0].getsizey() + 2);

	left_repeat[0].settype(EIGHT);
	left_repeat[1].settype(FOUR);
	left_repeat[2].settype(TWO);
	left_repeat[3].settype(ONE);

	right_repeat[0].setloc(860,535);
	right_repeat[1].setloc(860+right_repeat[0].getsizex() + 2,535);
	right_repeat[2].setloc(860,535 + right_repeat[0].getsizey() + 2);
	right_repeat[3].setloc(860+right_repeat[0].getsizex() + 2,535 + right_repeat[0].getsizey() + 2);

	right_repeat[0].settype(EIGHT);
	right_repeat[1].settype(FOUR);
	right_repeat[2].settype(TWO);
	right_repeat[3].settype(ONE);
	
	left_playpause.setloc(305,535);
	left_playpause.settype(TOGGLE);
	
	right_playpause.setloc(735,535);
	right_playpause.settype(TOGGLE);

	right_volume.setminvalue(0);
	right_volume.setmaxvalue(1);
	right_volume.setvalue(0);

	center_volume.setminvalue(0);
	center_volume.setmaxvalue(1);
	center_volume.setvalue(0.5);

	left_volume.setminvalue(0);
	left_volume.setmaxvalue(1);
	left_volume.setvalue(0);

	//font load
	ofTrueTypeFont::setGlobalDpi(72);
	myriadProBold.loadFont("MyriadPro-Bold.otf",12,true,true);
}
void virtual_dj_player::setup()
{
	component_init();
}
virtual_dj_player::virtual_dj_player()
{
	soundpad_pressed = false;
}
virtual_dj_player::~virtual_dj_player()
{
}
void virtual_dj_player::draw()
{
		 for(int i = 0 ; i < 16 ; i ++)
	{
		selector[i].draw();
	}

	for(int i = 0 ; i < 3 ; i++)
	{
		left_equalizer[i].draw();
		right_equalizer[i].draw();	
	}

	left_volume.draw();
	right_volume.draw();
	center_volume.draw();

	left_scratchplayer.draw();
	right_scratchplayer.draw();

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0 ; j < 4 ; j++)
		{
			soundpad[i][j].draw();
		}

		left_repeat[i].draw();
		right_repeat[i].draw();
	}

	left_playpause.draw();
	right_playpause.draw();

	//text draw
	ofSetColor(79,79,79);
	myriadProBold.drawString("selector",511,85);
	myriadProBold.drawString("equalizer",382,191);
	myriadProBold.drawString("equalizer",590,191);
	myriadProBold.drawString("volume",155,273);
	myriadProBold.drawString("volume",835,273);
	myriadProBold.drawString("soundpad",484,505);
	myriadProBold.drawString("volume",492,572);

	myriadProBold.drawString("repeat",85,525);
	myriadProBold.drawString("repeat",892,525);

	myriadProBold.drawString("play/pause",302,596);
	myriadProBold.drawString("play/pause",733,596);
}
void virtual_dj_player::clean_repeat(int leftright)
{
	for(int i = 0; i < 4; i++)
	{
		if(leftright == 0)
		{
			if(left_repeat[i].isOn)
			{
				left_repeat[i].onoff();
			}
		}
		else
		{
			if(left_repeat[i].isOn)
			{
				left_repeat[i].onoff();
			}
		}
	}

}
void virtual_dj_player::mouseDragged(int x, int y, int button,MediaManager* media)
{
	for(int i = 0 ; i < 3; i ++)
	{

		if(left_equalizer[i].setMouse(x,y))
		{
			media->ProcessingData(AUDIO,Equalizer,left_equalizer[i].getvalue(),i,0,-999);
		}

		if(right_equalizer[i].setMouse(x,y))
		{
			media->ProcessingData(AUDIO,Equalizer,right_equalizer[i].getvalue(),i,1,-999);
		}
	}

	if(left_volume.setMouse(x,y))
	{
		media->ProcessingData(AUDIO,Volume,1 - left_volume.getvalue(),0,-999,-999);
	}
	
	if(center_volume.setMouse(x,y))
	{
		media->ProcessingData(AUDIO,Volume,center_volume.getvalue(),2,-999,-999);
	}
	
	if(right_volume.setMouse(x,y))
	{
		media->ProcessingData(AUDIO,Volume,1 - right_volume.getvalue(),1,-999,-999);
	}
}
void virtual_dj_player::mousePressed(int x, int y, int button,MediaManager* media)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			if(soundpad[i][j].setMouse(x,y))
			{
				soundpad_pressed = true;
				media->ProcessingData(AUDIO,SoundPad,1,i,j,-999);
			}
		}
	}

	for(int i = 0 ; i < 4; i ++)
	{

		if(left_repeat[i].setMouse(x,y))
		{
			for(int k=0; k < 4; k++)
			{
				if(i != k)
				{
					if(left_repeat[k].isOn)
					{
						left_repeat[k].onoff();
					}
				}
			}

			if(left_repeat[i].isOn)
			{
				//repeat start
				media->ProcessingData(AUDIO,Repeat,1,i,0,-999);
			}
			else
			{
				//repeat off
				media->ProcessingData(AUDIO,Repeat,0,i,0,-999);
			}
		}
		
		if(right_repeat[i].setMouse(x,y))
		{
			for(int k = 0 ; k < 4; k++)
			{
				if( i != k)
				{
					if(right_repeat[k].isOn)
					{
						right_repeat[k].onoff();
					}
				}
			}

			if(right_repeat[i].isOn)
			{
				//repeat start
				media->ProcessingData(AUDIO,Repeat,1,i,1,-999);
			}
			else
			{
				//repeat off
				media->ProcessingData(AUDIO,Repeat,0,i,1,-999);
			}
		}
	}

	for(int i = 0 ; i < 16 ; i ++)
	{
		selector[i].setMouse(x,y);
	}


	if(left_playpause.setMouse(x,y))
	{
		if(left_playpause.isOn)
		{
			//true : play
			media->ProcessingData(AUDIO,Play,1,-999,0,-999);
			left_scratchplayer.isPlay = true;
		}
		else
		{
			//false : pause
			media->ProcessingData(AUDIO,Play,0,-999,0,-999);
			left_scratchplayer.isPlay = false;
		}
	}

	if(	right_playpause.setMouse(x,y))
	{
		if(right_playpause.isOn)
		{
			//true : play
			media->ProcessingData(AUDIO,Play,1,-999,1,-999);
			right_scratchplayer.isPlay = true;
		}
		else
		{
			media->ProcessingData(AUDIO,Play,0,-999,1,-999);
			right_scratchplayer.isPlay = false;
		}
	}
}
void virtual_dj_player::mouseReleased(int x, int y, int button,MediaManager* media)
{
	if(soundpad_pressed)
	{
		for(int i = 0 ; i < 4; i++)
		{
			for(int j = 0 ; j < 4; j++)
			{
				soundpad[i][j].off();
			}
		}

		soundpad_pressed = false;
	}
}
