/**
 * LIDARLite I2C Example
 * Author: Garmin
 * Modified by: Shawn Hymel (SparkFun Electronics)
 * Date: June 29, 2017
 * 
 * Read distance from LIDAR-Lite v3 over I2C
 * 
 * See the Operation Manual for wiring diagrams and more information:
 * http://static.garmin.com/pumac/LIDAR_Lite_v3_Operation_Manual_and_Technical_Specifications.pdf
 */

#include <Wire.h>
#include <LIDARLite.h>
#include <Servo.h>

// Globals
LIDARLite lidarLite;
int cal_cnt = 0;
int blocked = 0;

//Motors, ESC
Servo firstESC;
Servo secondESC;

int motorspeed;
int forward = 0;
int movementenabled = 1;

/*Botbitz
10 - No action
20 - No action
30 - Clockwise fast (looking towards motor from wheel)
60 - Clockwise slower (looking towards motor from wheel)
80 - Clockwise slow (looking towards motor from wheel)
90 - Stopped
100 - 
120 - Anticlockwise slower
150 - Anticlockwise fast
*/

//105 equivalent to 80

void setup()
{
  //Motors, ESC
  firstESC.attach(9);
  secondESC.attach(10);
  
  Serial.begin(9600); // Initialize serial connection to display distance readings

  lidarLite.begin(0, true); // Set configuration to default and I2C to 400 kHz
  lidarLite.configure(0); // Change this number to try out alternate configurations
}

void loop()
{
  //Start Motors
  if (movementenabled == 1){
  
  firstESC.write(70); 
  secondESC.write(115); 
  
  }

  
  int dist;

  // At the beginning of every 100 readings,
  // take a measurement with receiver bias correction
  if ( cal_cnt == 0 ) {
    dist = lidarLite.distance();      // With bias correction
  } else {
    dist = lidarLite.distance(false); // Without bias correction
  }

  // Increment reading counter
  cal_cnt++;
  cal_cnt = cal_cnt % 100;

  // Display distance

//Stop motors if too close to wall and play music

  if (dist < 40 && blocked==0){
    blocked = 1;
    //Serial.print("Blocked");
    Serial.println(dist);
    //Serial.println(" cm");
    movementenabled = 0;
    firstESC.write(90); 
    secondESC.write(90); 
  }

//Start motors once obstacle removed and stop music

  if (dist > 45 && blocked==1){
    blocked = 0;
    //Serial.print("Not blocked");
    Serial.println(dist); // Using Serial.println not Serial.print is important, raspberry pi won't be able to read the data otherwise with readline
    //Serial.println(" cm");
    movementenabled = 1;
  }
 
  delay(10);
}
