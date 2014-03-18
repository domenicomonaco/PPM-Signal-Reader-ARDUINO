//
//  PPMrcIn.cpp
//  Simple Library for Arduino to read/decode and manage PPM Signal from RC Reciever
//
//  Created by Domenico Monaco on 20/11/2011
//  Copyright 2011 Domenico Monaco - domenico.monaco@kiuz.it
//
//  License: GNU v2
//

#include "PPMrcIn.h"
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
  #else
  #include "WProgram.h"
#endif

#include <Statistic.h>

void Channel::init(int inv, int pin) {
    
    //sensibility are used to approximate Time Pulse
    //usefull on Middle position where there variation of value
	sensibility = ERROR;
    
	//Save Ping of channel
	if (pin)
		channelpin = pin; // channelpin[1] = 7, 7 is pin to read Channel 1
    
    //if option inverted are enabled, store config into class Channel
	if (inv != 1)
		invert = inv;
    
	//init Statics for current Channel
		ChannelStatistic = Statistic();
		ChannelStatistic.clear();
        
		PositionStatistic = Statistic();
		PositionStatistic.clear();


    //start configuration of Channel clas with output of Reciever
    configChannel();
    
}


void Channel::detectPosition() {
    //convert Microseconds Pulse into angle 0->180, where 90 are middle pos
	/*if (versus == 1) {
     position = initialsignal - signal;
     } else if (versus == -1) {
     
     position = signal - initialsignal;
     } else {
     
     position = 0;
     }*/
    position = map(signal,mininitialsignal,maxinitialsignal,ANGLERANGE_MIN,ANGLERANGE_MAX);
}

int Channel::getPosition() {
    return (position);
}

/**
 * Signal are Microseconds
 **/
unsigned long Channel::getSignal() {
    return signal;
}

/**
 *
 **/
void Channel::readSignal() {
	signal = pulseIn(channelpin, HIGH, 20000);
    
	saveStats();
	detectVersus();
}

void Channel::configChannel() {
    //initial value
	initialsignal = pulseIn(channelpin, HIGH);
    
	delay(2000);
    
    //Import first
	int i;
	for (i = 0; i < 100; i++) {
		readSignal();
		detectVersus();
        
		ChannelStatistic.add(signal);
	}
    
	mininitialsignal = ChannelStatistic.minimum();
	maxinitialsignal = ChannelStatistic.maximum();
    
}

void Channel::detectVersus() {
    // There are usefull "sensibility" where into inifluent changes of PulseIN
    // are ignored to canghe versus
    if (signal >= mininitialsignal - sensibility 
        && signal <= maxinitialsignal + sensibility) {
		versus = 0;
	} else if (signal < mininitialsignal - sensibility) {
		versus = 1;
	} else if (signal > maxinitialsignal + sensibility) {
		versus = -1;
	}
}

int Channel::getVersus() {
	return versus;
}

void Channel::saveStats() {
	ChannelStatistic.add(signal);
	PositionStatistic.add(position);
}
