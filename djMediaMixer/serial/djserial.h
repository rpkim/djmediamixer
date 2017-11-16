#pragma once
#include "ofMain.h"

#include "media/MediaManager.h"

class djserial
{
public:
	djserial();
	~djserial();
	void setup();
	void update();

	MediaManager *media;
	
private:
	void processingdata(unsigned char data[60],unsigned char b_data[60]);

	ofSerial	serial;
			
	bool		bSendSerialMessage;			// a flag for sending serial
	char		bytesRead[60];				// data from serial, we will be trying to read 60
	char		bytesReadString[61];			// a string needs a null terminator, so we need 60 + 1 bytes
	int			nBytesRead;					// how much did we read?
	int			nTimesRead;					// how many times did we read?
	float		readTime;					// when did we last read?		
	unsigned char bytesReturned[61];
	unsigned char bytesBeforeReturned[61];
	
};