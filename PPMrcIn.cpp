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
#include "WProgram.h"
#include <Statistic.h>

void ChannelStat::init() {
}

void Channel::init(int stat, int inv, int pin) {
    
	sensibility = 10;
    
	//Save Ping of channel
	if (pin)
		channelpin = pin; // channelpin[1] = 7, 7 is pin to read Channel 1
    
	if (inv != 1)
		invert = inv;
	//Enable Statics for current Channel
	if (stat) {
        
		ChannelStatistic = Statistic();
		ChannelStatistic.clear();
		PositionStatistic = Statistic();
		PositionStatistic.clear();
    }
	//initial value
	initialsignal = pulseIn(channelpin, HIGH);
    
	delay(2000);
    
	int i;
	for (i = 0; i < 100; i++) {
		readSignal();
		detectVersus();
        
		ChannelStatistic.add(signal);
	}
    
	mininitialsignal = ChannelStatistic.minimum();
	maxinitialsignal = ChannelStatistic.maximum();
    
}

int Channel::getPosition() {
    
    position = map(signal,mininitialsignal,maxinitialsignal,0,90);
    
	/*if (versus == 1) {
		position = initialsignal - signal;
    } else if (versus == -1) {
		
        position = signal - initialsignal;
	} else {
		
        position = 0;
	}*/
    
	return (position);
}

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
    
}

void Channel::detectVersus() {
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
