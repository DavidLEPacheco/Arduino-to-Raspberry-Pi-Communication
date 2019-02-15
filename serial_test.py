import serial #this is to communicate with arduino
import threading
import time
import sys
import pygame
from playmusic import play_music #playmusic is a separate file containing the function play_music, within the same project folder.
from multiprocessing import Queue
    
class myThread (threading.Thread):
   def __init__(self, threadID, name, counter):
      threading.Thread.__init__(self)
      self.threadID = threadID
      self.name = name
      self.counter = counter
   def run(self):
		
		while True:
			serial = q.get()
			if serial<40:
				play_music(music_file, volume)	
				
				while not q.empty():
					print(q.get())	
		return
		
def utf8len(s):
	return len(s.encode('utf-8'))
	
# Create new threads
thread1 = myThread(1, "Thread-1", 1)    

# Initialize queue variable to manage sound thread
q = Queue()
      
# Initialize serial communication
ser = serial.Serial('/dev/ttyACM0',9600)

# pick a MP3 music file you have in the working folder
# otherwise give the full file path
# (try other sound file formats too)
music_file = "/home/pi/Music/Move.mp3"
# optional volume 0 to 1.0
volume = 1.0
#play_music(music_file, volume)

mus = 1

while True:

      
	if not thread1.isAlive():
		mus = 1
    #read data from serial port, decode ascii characters and ignore non-ascii characters, and display
	read_serial=ser.readline() 
	read_serial=read_serial.decode('ascii','ignore')
	read_serial.strip() #use replace if value you want to discard is in centre of string, strip only works on outer edges.
   
	if 3<=len(read_serial)<=4: #Why does single digit have a length of 3 and double digit have length of 4? Still applies after removing newline and carriage return...
		#print read_serial
		#print utf8len(read_serial)
		read_serial = int(read_serial)
		print read_serial
		if read_serial<40:
			q.put(read_serial)
		
		if read_serial>45 and thread1.isAlive():
			pygame.mixer.music.stop()
			print("Not blocked")	
		
	if read_serial<>"" and mus<>0 :
		
		mus = 0
		thread1.start()  
	

       
        


    
