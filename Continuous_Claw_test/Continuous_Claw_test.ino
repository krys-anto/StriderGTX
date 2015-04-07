/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
 Serial.begin(9600);
 myservo.attach(53);
// myservo.write(92);// 92 Stop
//myservo.writeMicroseconds(1500);
// delay(500);
//myservo.write(92-5);// 0-91 closes
//myservo.writeMicroseconds(1500-100);
//delay(500);
//myservo.write(92+5); // 93-180 opens
//myservo.writeMicroseconds(1500+100);
} 

 
void loop() 
{ 
  Serial.println("Close");
  myservo.writeMicroseconds(1500-50);

  delay(1500);
  
  Serial.println("Stop");
  myservo.writeMicroseconds(1500);
  
  delay(1500);
  
  Serial.println("Open");
  myservo.writeMicroseconds(1500+35);
  
  delay(1500);

  Serial.println("Stop");
  myservo.writeMicroseconds(1500);
  delay(1500);
}

