#include <Ppmrc.h>

Channel channel1;

void setup() {

  Serial.begin(9600);
  
  Serial.println("Ready");

  pinMode (13, INPUT);
  channel1.init(1,1,13);
}

void loop() {
  delay(500);
  
  channel1.readSignal();
  channel1.detectVersus();
  
  Serial.println(channel1.getSignal());
  Serial.println(channel1.getPosition());
  Serial.println(channel1. getVersus());
  Serial.println("  ");
}






