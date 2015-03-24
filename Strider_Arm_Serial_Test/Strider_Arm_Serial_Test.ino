#include <Servo.h>

Servo rArm_Servo1;
Servo rArm_Servo2;
Servo rArm_Servo2b;
Servo rArm_Servo3;
Servo rArm_Servo4;
Servo rArm_Servo5;
Servo rClaw;

Servo lArm_Servo1;
Servo lArm_Servo2;
Servo lArm_Servo3;
Servo lArm_Servo4;
Servo lArm_Servo5;
Servo lClaw;

int ang = 0;
int currentAng = 0;

char buffer[] = {' ',' ',' ',' ',' ',' ',' '}; // Receive up to 7 bytes (Used to store the input from communication)
char pos[] = {' ', ' ', ' '};

int ang2;
int ang3;

int maxAng;

void setup()
{
	Serial.begin(9600); //Opens serial connection at 9600 baud rate
	
	rArm_Servo1.write(180);
	rArm_Servo2.write(170);
	rArm_Servo2b.write(180);
	rArm_Servo3.write(170);
	rArm_Servo4.write(170);
	rArm_Servo5.write(170);
	
	lArm_Servo1.write(5);
	lArm_Servo2.write(5);
	
	lArm_Servo3.write(5);
	lArm_Servo4.write(5);
	lArm_Servo5.write(5);
}

void loop()
{
	Serial.println("INput:");
	
	while(!Serial.available()); // waits untill serial communcation line is not avalible meaning that data was sent from the opposite host 
	Serial.readBytesUntil('n', buffer, 7);
	
	//Takes the postion input from the buffer
	for(int i = 0; i < 3; i++)
	{
		pos[0+i] = buffer[2+i];
		//Serial.println(i);
	}
	
	ang = atoi(pos);// Converts the Charater array numberica value to int type
	
	/* Used to see the contents taken from the stream
	Serial.print("buffer -> ");
	
	for(int i = 0; i < 7; i++)
	{
		Serial.println(buffer[i]);
	}
	
	Serial.print("Pos -> ");
	for(int i = 0; i < 3; i++)
	{
		Serial.println(pos[i]);
	}
	*/
	
	switch(buffer[0])
	{
		case 'R':
			Serial.print("Right Arm, ");
			switch(buffer[1])
			{
				case '1':
					currentAng = rArm_Servo1.read();
					if(currentAng < ang)
					{
						for(int pos = currentAng; pos < ang; pos += 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							rArm_Servo1.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}	
					}else{
						for(int pos = currentAng; pos > ang; pos -= 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							rArm_Servo1.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}
					}
					break;
				case '2':
					currentAng = rArm_Servo2.read();
					if(currentAng < ang)
					{
						for(int pos = currentAng; pos < ang; pos += 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							rArm_Servo2.write(pos);		// tell servo to go to position in variable 'pos'
							rArm_Servo2b.write(pos + 10);
							delay(15);			// waits 15ms for the servo to reach the position 
						}	
					}else{
						for(int pos = currentAng; pos > ang; pos -= 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							rArm_Servo2.write(pos);		// tell servo to go to position in variable 'pos'
							rArm_Servo2b.write(pos + 10);
							delay(15);			// waits 15ms for the servo to reach the position 
						}
					}
					break;
				case '3':
					currentAng = rArm_Servo3.read();
					if(currentAng < ang)
					{
						for(int pos = currentAng; pos < ang; pos += 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							rArm_Servo3.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}	
					}else{
						for(int pos = currentAng; pos > ang; pos -= 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							rArm_Servo3.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}
					}
					break;
				case '4':
					currentAng = rArm_Servo4.read();
					if(currentAng < ang)
					{
						for(int pos = currentAng; pos < ang; pos += 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							rArm_Servo4.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}	
					}else{
						for(int pos = currentAng; pos > ang; pos -= 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							rArm_Servo4.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}
					}
					break;
				case '5':
					currentAng = rArm_Servo5.read();
					if(currentAng < ang)
					{
						for(int pos = currentAng; pos < ang; pos += 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							rArm_Servo5.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}	
					}else{
						for(int pos = currentAng; pos > ang; pos -= 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							rArm_Servo5.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}
					}
					break;
				default:
					Serial.print("Buffer[1] -> ");
					Serial.println(buffer[1]);
					break;
			}
			break;
		case 'L':
			Serial.print("Left Arm, ");
			switch(buffer[1])
			{
				case '1':
					currentAng = lArm_Servo1.read();
					if(currentAng < ang)
					{
						for(int pos = currentAng; pos < ang; pos += 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							lArm_Servo1.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}	
					}else{
						for(int pos = currentAng; pos > ang; pos -= 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							lArm_Servo1.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}
					}
					break;
				case '2':
					currentAng = lArm_Servo2.read();
					if(currentAng < ang)
					{
						for(int pos = currentAng; pos < ang; pos += 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							lArm_Servo2.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}	
					}else{
						for(int pos = currentAng; pos > ang; pos -= 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							lArm_Servo2.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}
					}
					break;
				case '3':
					currentAng = lArm_Servo3.read();
					if(currentAng < ang)
					{
						for(int pos = currentAng; pos < ang; pos += 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							lArm_Servo3.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}	
					}else{
						for(int pos = currentAng; pos > ang; pos -= 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							lArm_Servo3.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}
					}
					break;
				case '4':
					currentAng = lArm_Servo4.read();
					if(currentAng < ang)
					{
						for(int pos = currentAng; pos < ang; pos += 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							lArm_Servo4.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}	
					}else{
						for(int pos = currentAng; pos > ang; pos -= 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							lArm_Servo4.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}
					}
					break;
				case '5':
					currentAng = lArm_Servo5.read();
					if(currentAng < ang)
					{
						for(int pos = currentAng; pos < ang; pos += 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							lArm_Servo5.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}	
					}else{
						for(int pos = currentAng; pos > ang; pos -= 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							lArm_Servo5.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}
					}
				case 'P':
					maxAng = max(abs(lArm_Servo2.read() - 130), max(abs(lArm_Servo3.read() - 45), abs(lArm_Servo3.read() - 45)));
					
					for(int i = 0; i < maxAng; i++)
					{
						lArm_Servo2.write((lArm_Servo2.read() < 130) ? lArm_Servo2.read() + 1 : lArm_Servo2.read() - 1);
						lArm_Servo3.write((lArm_Servo3.read() < 45) ? lArm_Servo3.read() + 1 : lArm_Servo3.read() - 1);
						lArm_Servo4.write((lArm_Servo4.read() < 45) ? lArm_Servo4.read() + 1 : lArm_Servo4.read() - 1);
						delay(15);
					}
					break;
				case 'C':
					currentAng = lClaw.read();
					if(currentAng < ang)
					{
						for(int pos = currentAng; pos < ang; pos += 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							lClaw.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}	
					}else{
						for(int pos = currentAng; pos > ang; pos -= 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							lClaw.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}
					}
					break;
					break;
				default:
					Serial.print("Buffer[1] -> ");
					Serial.println(buffer[1]);
					break;
			}
			break;
		case 'D':
			rArm_Servo1.detach(); // detaches(inputs the pin out to the Servo object) class) the servos to their respective pins
			rArm_Servo2.detach();
			rArm_Servo2b.detach();
			rArm_Servo3.detach();
			rArm_Servo4.detach();
			rArm_Servo5.detach();
			
			lArm_Servo1.detach(); // detaches(inputs the pin out to the Servo object) class) the servos to their respective pins
			lArm_Servo2.detach();
			lArm_Servo3.detach();
			lArm_Servo4.detach();
			lArm_Servo5.detach();
			break;
		case 'A':
			rArm_Servo1.attach(42); // Attaches(inputs the pin out to the Servo object) class) the servos to their respective pins
			rArm_Servo2.attach(44);
			rArm_Servo2b.attach(46);
			rArm_Servo3.attach(48);
			rArm_Servo4.attach(50);
			rArm_Servo5.attach(52);
			rClaw.attach(9);
			
			lArm_Servo1.attach(43); // Attaches(inputs the pin out to the Servo object) class) the servos to their respective pins
			lArm_Servo2.attach(45);
			lArm_Servo3.attach(47);
			lArm_Servo4.attach(49);
			lArm_Servo5.attach(51);
			lClaw.attach(10);
			break;
		default:
			break;
	}
	
	Serial.print("Servo = ");
	Serial.print(buffer[1]);
	Serial.print(", CurrentAngle = ");
	Serial.println(currentAng);
	Serial.print(", Angle = ");
	Serial.println(ang);
	
	for(int i = 0; i < 7; i++)
	{
		if(i < 3)
		{
			pos[i] = ' ';
		}
		buffer[i] = ' ';
	}
}
>>>>>>> origin/master
