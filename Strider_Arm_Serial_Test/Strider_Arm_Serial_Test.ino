#include <Servo.h>

Servo rArm_Servo1;
Servo rArm_Servo2;
Servo rArm_Servo3;
Servo rArm_Servo4;
Servo rArm_Servo5;

int ang = 0;

char buffer[] = {' ',' ',' ',' ',' ',' ',' '}; // Receive up to 7 bytes (Used to store the input from communication)
char pos[] = {' ', ' ', ' '};

void setup()
{
	Serial.begin(9600); //Opens serial connection at 9600 baud rate
	
	rArm_Servo1.attach(42); // Attaches(inputs the pin out to the Servo object) class) the servos to their respective pins
	rArm_Servo2.attach(44);
	rArm_Servo3.attach(46);
	rArm_Servo4.attach(48);
	rArm_Servo5.attach(50);
	
	rArm_Servo1.write(5);
	rArm_Servo2.write(5);
	rArm_Servo3.write(5);
	rArm_Servo4.write(5);
	rArm_Servo5.write(5);
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
			Serial.print("Servo = ");
			Serial.print(buffer[1]);
			Serial.print(", Angle = ");
			Serial.println(ang);
			
			switch(buffer[1])
			{
				case '1':
					rArm_Servo1.write(ang);
					break;
				case '2':
					rArm_Servo2.write(ang);
					break;
				case '3':
					rArm_Servo3.write(ang);
					break;
				case '4':
					rArm_Servo4.write(ang);
					break;
				case '5':
					rArm_Servo5.write(ang);
					break;
				default:
					Serial.print("Buffer[1] -> ");
					Serial.println(buffer[1]);
					break;
				
			}
			break;
		default:
			break;
	}
	
	Serial.print("Servo = ");
	Serial.print(buffer[1]);
	
	for(int i = 0; i < 3; i++)
	{
		if(i < 3)
		{
			pos[i] = ' ';
		}
		buffer[i] = ' ';
	}
}
