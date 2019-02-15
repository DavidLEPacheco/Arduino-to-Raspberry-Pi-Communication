# Arduino-to-Raspberry-Pi-Communication

This code allows communication between the Arduino and Raspberry Pi. In this particular implementation, the Arduino is controlling motors on a robotic platform. A LIDAR mounted on the front of the platform senses when an object or person is in its way (within 40cm) and stops the motors. At the same time, it sends a command to the Raspberry Pi on the serial port. The Raspberry Pi reads this signal and starts playing "Move bitch get out the way" by Ludacris through a speaker connected to the Auxiliary port. When the object or person moves out of the way, the music stops and the platform starts moving again.  

Upload RaspberryPi_Communication_LidarLiteMotorControl.ino to Arduino

Add serial_test.py and playmusic.py to the same project folder on the Raspberry Pi

The music plays in a separate thread so that it can be killed when receiving a signal from the arduino that the object or person has been removed. In a serial program the music would continue to play until the end of the sound file.
