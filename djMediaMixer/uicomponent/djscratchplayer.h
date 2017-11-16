#pragma once
#include "ofMain.h"

class djscratchplayer
{
public:
	djscratchplayer();
	void draw();
	void setloc(int _x,int _y);
	bool isPlay;
private:
	int x;
	int y;
	int bgR;
	int centerR;

	double g_dgree;
};
