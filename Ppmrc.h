#ifndef Ppmrc_h
#define Ppmrc_h

#define STEER_PROP 0.15

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

private:
	int channelpin;
	int invert;

	unsigned long signal;
	unsigned long initialsignal;

	unsigned long mininitialsignal;
	unsigned long maxinitialsignal;
        int sensibility;
        
        int versus;
        
        int positionsteer;
        
	ChannelStat Statistic;
};

#endif
