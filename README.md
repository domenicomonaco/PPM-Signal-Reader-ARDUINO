#PPM Radio Control Signal Reader#

[![Tested](http://img.shields.io/badge/Tested-ok-brightgreen.svg)](https://github.com/kiuz/PPM-Signal-Reader-ARDUINO)
[![GPL V2 License](http://img.shields.io/badge/License-GPLv2-red.svg)](http://www.gnu.org/licenses/gpl-2.0.html)
[![Gratipay Badge](http://img.shields.io/badge/Gratipay-kiuzhack-green.svg)](https://gratipay.com/kiuzhack)

##Intro##
Simple library to manage output of Radio Control receiver

* Author: Domenico Monaco
* e-mail: domenico.monaco AT kiuz.it
* Site: http://monaco.kiuz.it

## Description
This library allows you to read Pulse Position Modulation (PPM) signals from Radio Control receiver of classical RC Car or other Devices.

## Special Thanks ##
* [justy](https://github.com/justy), justy256@gmail.com
* Jeff McAlvay, jeff@jeffsinventions.com - <http://jeffsinventions.com/autonomous-car-manual-override/>
	* thanks for some little feedback and implementation

## Dependencies ##
[DEPRECATED] You must be install into libraries Statistic Library
http://github.com/kiuz/Arduino-Statistic-Library

[NEW] Now I've included Arduino-Statistic-Library as Sub-repositories, you can follow Installation Section in this file.

## TESTED ARDUINO LIBRARY ##
* 1.0.6 tested and work (thanks to [flavbleach](https://github.com/flavbleach))
* 1.8.* does not want to work properly (thanks to [flavbleach](https://github.com/flavbleach))

## Changes ##

* 0.1 - initial 
* 0.2 - 
	* fixed #include Wprogram.h into Arduino.h
		* http://arduino.cc/en/Main/ReleaseNotes#.UyizMq15OtU
	* fixed ppmrcin.h into PPMrcIn.h
	* changed folder tree to best use into Arduino libraries

## Installation ##
* After cloning the repository you must copy "PPmSignalReader" and "Statistic" into "Arduino/libraries/" folder
* Open or re-Open Arduino IDE and now you can use PPmSignalReader library or open Example form menu
