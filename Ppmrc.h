//
//  Ppmrc.h
//  Simple Library for Arduino to read/decode and manage PPM Signal from RC Reciever
//
//  Created by Domenico Monaco on 20/11/2011
//  Copyright 2011 Domenico Monaco - domenico.monaco@kiuz.it
//
//  License: GNU v2
//

#ifndef Ppmrc_h
#define Ppmrc_h
#include <Statistic.h>

#define STEER_PROP 0.5

class ChannelStat {
public:
	void init();
};

class Channel {
public:
	void init(int stat, int inv, int pin);

	int getPosition();

	unsigned long getSignal();

	void readSignal();

	void configChannel();

	void detectVersus();

	int getVersus();

	void saveStats();

	Statistic PositionStatistic;
	Statistic ChannelStatistic;

private:
	int channelpin;
	int invert;

	unsigned long signal;
	unsigned long initialsignal;

	unsigned long mininitialsignal;
	unsigned long maxinitialsignal;
	int sensibility;

	int versus;

	unsigned int position;


};

#endif
