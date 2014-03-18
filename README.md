#PPM Rardio Controller Signal Reader#

##Intro##
Simple library to manage output of Radio Controll reciever

* Author: Domenico Monaco
* e-mail: domenico.monaco AT kiuz.it
* Site: http://monaco.kiuz.it

## Description
This library help you reading Pluse-In from Radio Controll reciever of classical RC Car or other Devices.

## Special Thanks ##
* Jeff McAlvay, jeff@jeffsinventions.com - <http://jeffsinventions.com/autonomous-car-manual-override/>
	* thanks for some little feedback and implementation

## Dependencies ##
[DEPRECATED] You must be install into libraries Statistic Library
http://github.com/kiuz/Arduino-Statistic-Library

[NEW] Now I've included Arduino-Statistic-Library as Sub-repositories, you can follow Installation Section in this file.

## Changes ##

* 0.1 - initial 
* 0.2 - 
	* fixed #include Wprogram.h into Arduino.h
		* http://arduino.cc/en/Main/ReleaseNotes#.UyizMq15OtU
	* fixed ppmrcin.h into PPMrcIn.h
	* changed folder tree to best use into Arduino libraries


## Installation ##
* After cloning repo you must copy "PPmSignalReader" and "Statistic" into "Arduino/libraries/" folder
* Open or re-Open Arduino IDE and now you can use PPmSignalReader library or open Example form menu