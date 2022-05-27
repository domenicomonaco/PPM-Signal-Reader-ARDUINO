#PPM Radio Control Signal Reader#

[![Tested](http://img.shields.io/badge/Tested-ok-brightgreen.svg)](https://github.com/kiuz/PPM-Signal-Reader-ARDUINO)
[![GPL V2 License](http://img.shields.io/badge/License-GPLv2-red.svg)](http://www.gnu.org/licenses/gpl-2.0.html)
[![Gratipay Badge](http://img.shields.io/badge/Gratipay-kiuzhack-green.svg)](https://gratipay.com/kiuzhack)

##Intro##
Simple library to manage output of Radio Control receiver

* Author: Domenico Monaco
* e-mail: domenico@tecnologieperpersone.it
* Site: https://domenicomonaco.it

### Sponsored by

[<img align="left" style="margin:5px" src="http://cdn.tecnologieperpersone.it/img/dmonaco_happy_hacking.png" height="64" />](https://blog.domenicomonaco.it)

[<img style="margin:5px" src="http://cdn.tecnologieperpersone.it/img/tecnologie-per-persone-logo.png" height="64" />](https://tecnologieperpersone.it)



## Description
This library allows you to read Pulse Position Modulation (PPM) signals from Radio Control receiver of classical RC Car or other Devices.

## Special Thanks ##
* [flavbleach](https://github.com/flavbleach)
* [justy](https://github.com/justy), justy256@gmail.com
* Jeff McAlvay, jeff@jeffsinventions.com - <http://jeffsinventions.com/autonomous-car-manual-override/>
	* thanks for some little feedback and implementation

## Dependencies ##
[DEPRECATED] You must be install into libraries Statistic Library
http://github.com/kiuz/Arduino-Statistic-Library

[NEW] Now I've included Arduino-Statistic-Library as Sub-repositories, you can follow Installation Section in this file.

## TESTED ARDUINO LIBRARY ##
* 1.0.6 [![Tested](http://img.shields.io/badge/Tested-SUCCESS-brightgreen.svg)](https://github.com/kiuz/PPM-Signal-Reader-ARDUINO) (thanks to [flavbleach](https://github.com/flavbleach))
* 1.8.* [![FAILED-TEST](http://img.shields.io/badge/Tested-FAILED-brightred.svg)](https://github.com/kiuz/PPM-Signal-Reader-ARDUINO) (thanks to [flavbleach](https://github.com/flavbleach))

## OPEN ISSUE ##
 * #4 and #5,"Compatibility with Arduino IDE 1.8" where seems doesn't work with over 3 pins input.

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
