# CrOSser

![CrOSser 2x small](https://github.com/marcexec/CrOSser/assets/62036115/227bcc1e-a075-4b3f-86b0-7ab73f379d77)


ChromeOS and ChromeOS Flex enrollment with USB enabled Arduino clone (Digispark / ATTiny85 USB) emulating a USB keyboard.
This will enabled admins and non-admins to enroll batches of (ideally similar) ChromeOS devices with little effort.
Just turn the device on and plug the programmed Digispark in. 
Note that passwords are hardcoded and will be "typed" into e.g. a text editor window on any computer when plugged in.

A similar sketch is available to install ChromeOS semi-automatically (post booting from USB in the BIOS): https://github.com/marcexec/CrOSser-Flex

## Updates
* 2023-10-24 V1.0.0 commit

## How it works

The Ardunio sketch basically just emulates timed key presses of a USB keyboard. It's crude but adaptable and the code should be easy to follow and adjust e.g. to skip WiFi when a wired connection is available or you have slower devices (ChromeOS Flex, https://support.google.com/chromeosflex/answer/11552529) and want to increase delays.

Requires https://github.com/digistump/DigisparkArduinoIntegration/blob/master/libraries/DigisparkKeyboard/DigiKeyboard.h

## Getting Started
I have a full writeup, including the Arduino IDE setup on ChromeOS on the CitrixIE blog: https://citrixie.wordpress.com/2023/03/02/using-5-open-source-hardware-for-chromeos-enterprise-enrollment-and-chromeos-flex-installation/
