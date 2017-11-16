#include "djserial.h"

djserial::djserial()
{
}
djserial::~djserial()
{
}
void djserial::setup()
{
	serial.setup("COM5",9600);
	nTimesRead = 0;
	nBytesRead = 0;
	readTime = 0;
	memset(bytesReadString, 0, 4);
	memset(bytesBeforeReturned,0,60);
	
	bytesBeforeReturned[0] = 0x53;
	bytesBeforeReturned[59] = 0x45;


	bSendSerialMessage = true;

}

string GetString(unsigned char* inStrReference) {
   return (char *)inStrReference;
}
void djserial::update()
{
	int nRead  = 0;  // a temp variable to keep count per read
	nBytesRead = 0;

	memset(bytesReadString, 0, 61);
	memset(bytesReturned, 0, 60); 
		
	if(serial.available() > 59) {
 
		while( (nRead = serial.readBytes( bytesReturned, 60)) > 0){
			nTimesRead++;	
			nBytesRead = nRead;
		};

	}

	if(nBytesRead > 0 ) 
	{
		memcpy(bytesReadString, bytesReturned, 60);

		if(bytesReturned[0] == 'S' && bytesReturned[59] == 'E')
		{

			if(bytesReturned != bytesBeforeReturned)
			{
					//processing
					processingdata(bytesReturned,bytesBeforeReturned);
			}

			memcpy(bytesBeforeReturned, bytesReturned, 60);
		}
		else
		{
			string str = GetString(bytesReturned);
			ofLogWarning() << "STX,ETX error : " << str;
		}
	}
}
void djserial::processingdata(unsigned char data[60],unsigned char b_data[60])
{
	for(int i = 0; i < 60; i++)
	{
		if((int)data[i] != (int)b_data[i])
		{
			if(i >= 1 && i <= 12)			//Selector
			{
				if(data[i] == 0x01)
				{
					media->ProcessingData(Selector,1,i-1,-955,-955);
				}
				else
				{
					media->ProcessingData(Selector,0,i-1,-955,-955);
				}
			}
			if(i >= 13 && i <= 21)			//sound pad
			{
				if(data[i] == 0x01)
				{
					int number = i-13;
					int num = (int)(number % 2);
					int temp01 = (int)(number / 2);

					media->ProcessingData(SoundPad,1,num,temp01,-999);
				}
			}
			if(i >= 22 && i <= 25)	//left repeat is ok
			{
				if(data[i] == 0x01)
				{
					media->ProcessingData(Repeat,1,3 - (25-i),0,-999);
				}
				else
				{
					media->ProcessingData(Repeat,0,3 - (25-i),0,-999);
				}
			}
			if(i >= 26 && i <= 29)	//right repeat is ok
			{
				if(data[i] == 0x01)
				{
					media->ProcessingData(Repeat,1,3 - (29-i),1,-999);
				}
				else
				{
					media->ProcessingData(Repeat,0,3 - (29-i),1,-999);
				}
			}
			if(i == 30)				//left play is ok
			{
				if(data[i] == 0x01)
				{
					media->ProcessingData(Play,1,-999,0,-999);
				}
				else
				{
					media->ProcessingData(Play,0,-999,0,-999);
				}
			}
			if(i == 31)				// right play is ok
			{
				if(data[i] == 0x01)
				{
					media->ProcessingData(Play,1,-999,1,-999);
				}
				else
				{
					media->ProcessingData(Play,0,-999,1,-999);
				}
			}
			if(i >= 32 && i <= 34)	//left equalizer
			{
				float fdata= (float)data[i];
				//data 0 ~ 2 로 변환 ( 0 ~ 100 에서 )
				media->ProcessingData(Equalizer,fdata/50.0,i-32,0,-999);
			}
			if(i >= 35 && i <= 37)	//right equlaizer
			{
				float fdata= (float)data[i];
				//data 0 ~ 2 로 변환 ( 0 ~ 100 에서 )
				media->ProcessingData(Equalizer,fdata/50.0,i-35,1,-999);
			}
			if(i >= 38 && i <= 39)	//left right _ volume
			{
				float fdata= (float)data[i];
				//data 0 ~ 2 로 변환 ( 0 ~ 100 에서 )
				media->ProcessingData(Volume,fdata/100.0,i-38,-999,-999);
			}
			if(i == 40)				//center volume
			{
				float fdata= (float)data[i];
				//data 0 ~ 2 로 변환 ( 0 ~ 100 에서 )
				media->ProcessingData(Volume,fdata/100.0,2,-999,-999);
			}
			if(i >= 41 && i <= 43)	//turn table
			{
			}
		}
	}
}
