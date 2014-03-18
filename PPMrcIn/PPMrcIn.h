//
//  PPMrcIn.h
//  Simple Library for Arduino to read/decode and manage PPM Signal from RC Reciever
//
//  Created by Domenico Monaco on 20/11/2011
//  Copyright 2011 Domenico Monaco - domenico.monaco@kiuz.it
//
//  License: GNU v2
//

#ifndef PpmrcIn_h
#define PpmrcIn_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
  #else
  #include "WProgram.h"
#endif

#include <Statistic.h>

//Used to approximate PulseIn with errors
#define ERROR 10

//Angle of range conversion
#define ANGLERANGE_MIN 0
#define ANGLERANGE_MAX 180

class Channel {
public:
    
	void init(int inv, int pin);
    
	unsigned long getSignal();
    
    void readSignal();

	int getVersus();
    
    int getPosition();

private:
    void configChannel();
    void detectVersus();
    void detectPosition();
    void saveStats();
    
    Statistic PositionStatistic;
	Statistic ChannelStatistic;
    
    //pin where are connected rc out
	int channelpin;
    
    //configuration
        //Invert output
	int invert;
    
        //Sensibility of reading pulseIn
	int sensibility;
    
        //middle middle signal recieved
	unsigned long initialsignal;
        //min value signal recievd
	unsigned long mininitialsignal;
        //max value signal recieved
	unsigned long maxinitialsignal;

    //last values reading
        //microsecons of pulseIn
    unsigned long signal;
    
        //versus of command respect of middle
        //0: Middle
        //1 and -1 at extreme
	int versus;
    
        // Angle conversion of PulseIns
        // Default are 0-180
	unsigned int position;
};

#endif
