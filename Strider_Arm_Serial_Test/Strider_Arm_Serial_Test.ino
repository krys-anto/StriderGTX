#include <Servo.h>

#define R_ARM1_PIN 42
#define R_ARM2_PIN 44
#define R_ARM3_PIN 46
#define R_ARM4_PIN 48
#define R_ARM5_PIN 50
#define R_ARMC_PIN 52

#define L_ARM1_PIN 43
#define L_ARM2_PIN 45
#define L_ARM3_PIN 47
#define L_ARM4_PIN 49
#define L_ARM5_PIN 51
#define L_ARMC_PIN 53

Servo rArm_Servo1;
Servo rArm_Servo2;
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
		case 'I':
			rArm_Servo1.write(160);
			rArm_Servo2.write(170);
			rArm_Servo3.write(180);
			rArm_Servo4.write(180);
			rArm_Servo5.write(170);
			
			lArm_Servo1.write(5);
			lArm_Servo2.write(5);
			
			lArm_Servo3.write(5);
			lArm_Servo4.write(5);
			lArm_Servo5.write(5);
			break;
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
							delay(15);			// waits 15ms for the servo to reach the position 
						}	
					}else{
						for(int pos = currentAng; pos > ang; pos -= 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							rArm_Servo2.write(pos);		// tell servo to go to position in variable 'pos'
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
				case 'C':
					currentAng = rClaw.read();
					if(currentAng < ang)
					{
						for(int pos = currentAng; pos < ang; pos += 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							rClaw.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}	
					}else{
						for(int pos = currentAng; pos > ang; pos -= 1) 	// goes from 0 degrees to 180 degrees 
						{						// in steps of 1 degree 
							rClaw.write(pos);		// tell servo to go to position in variable 'pos' 
							delay(15);			// waits 15ms for the servo to reach the position 
						}
					}
					break;
				case 'A':
					Serial.println("===Current positions:===");
					Serial.print("Servo 1 =>");
					Serial.println(rArm_Servo1.read());
					Serial.print("Servo 2 =>");
					Serial.println(rArm_Servo2.read());
					Serial.print("Servo 3 =>");
					Serial.println(rArm_Servo3.read());
					Serial.print("Servo 4 =>");
					Serial.println(rArm_Servo4.read());
					Serial.print("Servo 5 =>");
					Serial.println(rArm_Servo5.read());
					break;
				case 'N':
					//break;
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
					break;
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
					switch(buffer[2])
					{
						for(int i = 0; i < 2; i++)
						{
							pos[i] = buffer[i + 3];
						}
						
						ang = atoi(pos);
						case 'O':
							myservo.writeMicroseconds(1500+35);
  							delay(ang * 100);
							break;
						case 'C':
							myservo.writeMicroseconds(1500-50);
							delay(ang * 100);
							break;
						case 'S':
							lClaw.writeMicroseconds(1500);
							break;
					}
					break;
				case 'A':
					Serial.println("===(Current positions:)===");
					Serial.print("Servo 1 =>");
					Serial.println(lArm_Servo1.read());
					Serial.print("Servo 2 =>");
					Serial.println(lArm_Servo2.read());
					Serial.print("Servo 3 =>");
					Serial.println(lArm_Servo3.read());
					Serial.print("Servo 4 =>"); 
					Serial.println(lArm_Servo4.read());
					Serial.print("Servo 5 =>");
					Serial.println(lArm_Servo5.read());
					break;
				case 'N':
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
			switch(buffer[1])
			{
				case 'A':
					rArm_Servo1.attach(R_ARM1_PIN); // Attaches(inputs the pin out to the Servo object) class) the servos to their respective pins
					rArm_Servo2.attach(R_ARM2_PIN);
					rArm_Servo3.attach(R_ARM3_PIN);
					rArm_Servo4.attach(R_ARM4_PIN);
					rArm_Servo5.attach(R_ARM5_PIN);
					rClaw.attach(R_ARMC_PIN);
					
					lArm_Servo1.attach(L_ARM1_PIN); // Attaches(inputs the pin out to the Servo object) class) the servos to their respective pins
					lArm_Servo2.attach(L_ARM2_PIN);
					lArm_Servo3.attach(L_ARM3_PIN);
					lArm_Servo4.attach(L_ARM4_PIN);
					lArm_Servo5.attach(L_ARM5_PIN);
					lClaw.attach(L_ARMC_PIN);
					break;
				case 'R':
					switch(buffer[2])
					{
						case '1':
							rArm_Servo1.attach(R_ARM1_PIN);
							break;
						case '2':
							rArm_Servo2.attach(R_ARM2_PIN);
							break;
						case '3':
							rArm_Servo3.attach(R_ARM3_PIN);
							break;
						case '4':
							rArm_Servo4.attach(R_ARM4_PIN);
							break;
						case '5':
							rArm_Servo5.attach(R_ARM5_PIN);
							break;
						case 'C':
							rClaw.attach(R_ARMC_PIN);
							break;
						default:
							Serial.print("buffer[3] => ");
							Serial.println(buffer[3]);
							break;
					}
					break;
				case 'L':
					switch(buffer[2])
					{
						case '1':
							lArm_Servo1.attach(L_ARM1_PIN);
							break;
						case '2':
							lArm_Servo2.attach(L_ARM2_PIN);
							break;
						case '3':
							lArm_Servo3.attach(L_ARM3_PIN);
							break;
						case '4':
							lArm_Servo4.attach(L_ARM4_PIN);
							break;
						case '5':
							lArm_Servo5.attach(L_ARM5_PIN);
							break;
						case 'C':
							lClaw.attach(L_ARMC_PIN);
							break;
						default:
							Serial.print("buffer[3] => ");
							Serial.println(buffer[3]);
							break;
					}
					break;
				default:
					Serial.print("buffer[2] => ");
					Serial.println(buffer[2]);
					break;
			}
			break;
		default:
			Serial.print("buffer[1] => ");
			Serial.println(buffer[1]);
			break;
	}
	
	Serial.println();
	Serial.print("Servo = ");
	Serial.println(buffer[1]);
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
