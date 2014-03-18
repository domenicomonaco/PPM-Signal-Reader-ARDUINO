//
//  ReadSignalFromRC.pde
//  Example for PPMrcIn Arduino Library
//
//  Created by Domenico Monaco on 20/11/2011
//  Copyright 2011 Domenico Monaco - domenico.monaco@kiuz.it
//
//  License: GNU v2
//

#include <PPMrcIn.h>

// must be install into libraries http://github.com/kiuz/Arduino-Statistic-Library

#include <Statistic.h>

//init a Channel class to store and manage CannelX form reciever
Channel channel1;

void setup() {
  Serial.begin(9600);
 
  Serial.println("Ready:");

  pinMode (13, INPUT);
  channel1.init(1,13);
}

void loop() {
  delay(20);
  
  channel1.readSignal();
  
  Serial.println(channel1.getSignal());
  Serial.println(channel1.getPosition());
  Serial.println(channel1.getVersus());
  Serial.println(" ");
}
