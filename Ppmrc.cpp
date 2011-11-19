#include "ppmrc.h"
#include "WProgram.h"

void ChannelStat::init() {
}


void Channel::init(int stat, int inv, int pin) {

                sensibility = 10;

		//Save Ping of channel
		if (pin) channelpin = pin; // channelpin[1] = 7, 7 is pin to read Channel 1

		if (inv != 1) invert = inv;
		//Enable Statics for current Channel
		if (stat) {
			Statistic = ChannelStat();
			Statistic.init();
		}
  
  //initial value
  initialsignal = pulseIn (channelpin, HIGH, 20000);
  
  
  
  //
  unsigned long signalScan[100];
  int i;
  
  for(i=0;i<100;i++){
    signalScan[i] = pulseIn (channelpin, HIGH,20000);
  }

  for(i=0;i<100-1;i++){
    mininitialsignal = min(signalScan[i],signalScan[i+1]);
    maxinitialsignal = max(signalScan[i],signalScan[i+1]);
  }
  
}

int Channel::getPosition() {
        
  if (versus==1) {
    positionsteer = signal - initialsignal;
  } 
  else {
    positionsteer = initialsignal - signal;
  }
  positionsteer = positionsteer * STEER_PROP; // convert to 0-100 range
  constrain (positionsteer, 0, 100); //just in case
  
  return positionsteer;
}



unsigned long Channel::getSignal() {
	return signal;
}

/**
 *
**/
void Channel::readSignal() {
  signal = pulseIn (channelpin, HIGH, 20000);
  detectVersus();
}

void Channel::configChannel() {

}


void Channel::detectVersus(){
if(signal >= mininitialsignal - sensibility && signal <= maxinitialsignal + sensibility){
versus = 0;
}
else if (signal < mininitialsignal - sensibility) {
versus = 1;
} 
else if(signal > maxinitialsignal + sensibility)  {
versus = -1;
}

}
int Channel::getVersus(){
return versus;
}
