# Arduino-to-Raspberry-Pi-Communication

This repository establishes communication between the Raspberry Pi (in Python) and the Arduino (in C) using the serial port. It can be used for projects which require both real time control of hardware from a microcontroller and the additional functionality offered by a microcomputer (computer vision, sound, external communication etc) .

In this particular implementation, the Arduino is controlling motors on a robotic platform. A LIDAR mounted on the front of the platform senses when an object or person is in its way (within 40cm) and stops the motors. At the same time, it sends a command to the Raspberry Pi on the serial port. The Raspberry Pi reads this signal and starts playing "Move Bitch Get Out Da Way" by Ludacris through a speaker connected to the Auxiliary port. When the object or person moves out of the way, the music stops and the platform starts moving again. The music plays in a separate thread so that it can be killed when receiving a signal from the arduino that the object or person has been removed. In a serial program the music would continue to play until the end of the sound file, even if the person or object had moved long ago.


You do not need  access to this hardware and can strip away any irrelevant code to test the communication interface directly.

Upload RaspberryPi_Communication_LidarLiteMotorControl.ino to Arduino

Add serial_test.py and playmusic.py to the same project folder on the Raspberry Pi

