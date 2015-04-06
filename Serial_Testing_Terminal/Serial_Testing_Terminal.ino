#include <Servo.h>

Servo myservo;

#define MFR_A_PIN	11   	// FRONT RIGHT MOTOR
#define MFR_B_PIN	12
#define MFR_PWM_PIN	13	// PULSE WIDTH MODULATION PIN

#define MFL_A_PIN	5	//FRONT LEFT MOTOR
#define MFL_B_PIN 	6
#define MFL_PWM_PIN	7	 // PULSE WIDTH MODULATION PIN

#define MBR_A_PIN	9	//BACK RIGHT MOTOR
#define MBR_B_PIN	10
#define MBR_PWM_PIN	8	// PULSE WIDTH MODULATION PIN

#define MBL_A_PIN	3	//BACK LEFT MOTOR
#define MBL_B_PIN	4
#define MBL_PWM_PIN	2 	// PULSE WIDTH MODULATION PIN 

void setup()
{
	Serial.begin(9600);
	  
	//Define L298N Dual H-Bridge Motor Controller Pins
	
	// Three pins for each motor.
	
	// Motor Front Right Side  
	
	pinMode(MFR_A_PIN,OUTPUT);
	pinMode(MFR_B_PIN,OUTPUT);
	pinMode(MFR_PWM_PIN,OUTPUT);// Controls speed- Pulse width modulation
	
	// Motor Front Left Side
	pinMode(MFL_A_PIN,OUTPUT);
	pinMode(MFL_B_PIN,OUTPUT);
	pinMode(MFL_PWM_PIN,OUTPUT);
	 
	// Motor Back Right Side
	pinMode(MBR_A_PIN,OUTPUT);
	pinMode(MBR_B_PIN,OUTPUT);
	pinMode(MBR_PWM_PIN,OUTPUT);
	
	// Motor Back Left Side
	pinMode(MBL_A_PIN,OUTPUT);
	pinMode(MBL_B_PIN,OUTPUT);
	pinMode(MBL_PWM_PIN,OUTPUT);
	
	// Initializing all the speed values to 0
	
	analogWrite(MFR_PWM_PIN, 0);
	analogWrite(MFL_PWM_PIN, 0);
	
	analogWrite(MBR_PWM_PIN, 0);
	analogWrite(MBL_PWM_PIN, 0);
}


int mSpeed = 0;

int mSpeedFR = 0;
int mSpeedBR = 0;

int mSpeedFL = 0;
int mSpeedBL = 0;

int PIN = -1;
int ANG = -1;

char buffer[] = {' ',' ',' ',' ',' ',' ',' '}; // Receive up to 7 bytes (Used to store the input from communication)
char pwm[] = {' ', ' ', ' '};
char serialInput;

void loop()
{
	serialInput = '0';
	Serial.println("---MAIN MENU---");
	
	while (!Serial.available());
	

		switch(Serial.read())
		{
			case 'N':
				Serial.println("Navigation Test");
				
				mSpeed = 0;
				while(serialInput != '<')
				{
					while (!Serial.available());
					serialInput = Serial.read();
					switch(serialInput)
					{
						case 'F': // Forward Test
			
							Serial.println("Motor Forward Test Low, High");
								
							// Setting  direction 
							
							digitalWrite(MFR_A_PIN, LOW);
							digitalWrite(MFR_B_PIN, HIGH);
							
							digitalWrite(MFL_A_PIN, LOW);
							digitalWrite(MFL_B_PIN, HIGH);
							
							digitalWrite(MBR_A_PIN, HIGH);
							digitalWrite(MBR_B_PIN, LOW);
							
							digitalWrite(MBL_A_PIN, HIGH);
							digitalWrite(MBL_B_PIN, LOW);
							
								// Sending Instruction to start movement
							
							break;
						
						case 'B': // Motor BACKWARD
						
							Serial.println("Motor Backward Test High, Low");
							
							// Setting  direction
								
							digitalWrite(MFR_A_PIN, HIGH);
							digitalWrite(MFR_B_PIN, LOW);
							
							digitalWrite(MFL_A_PIN, LOW);
							digitalWrite(MFL_B_PIN, HIGH);
							
							digitalWrite(MBR_A_PIN, HIGH);
							digitalWrite(MBR_B_PIN, LOW);
							
							digitalWrite(MBL_A_PIN, LOW);
							digitalWrite(MBL_B_PIN, HIGH);
							
							// Sending Instruction to start movement
						
							break;
							
						case 'R': // Motor TURN RIGHT
						
							Serial.println("Motor Right Test High, Low");
							
							// Setting  direction
								
							digitalWrite(MFR_A_PIN, HIGH);
							digitalWrite(MFR_B_PIN, LOW);
							
							digitalWrite(MFL_A_PIN, HIGH);
							digitalWrite(MFL_B_PIN, LOW);
							
							digitalWrite(MBR_A_PIN, HIGH);
							digitalWrite(MBR_B_PIN, LOW);
							
							digitalWrite(MBL_A_PIN, HIGH);
							digitalWrite(MBL_B_PIN, LOW);
							
							// Sending Instruction to start movement
						
							break;
							
						case 'L': // Motor TURN LEFT
						
							Serial.println("Motor Forward Test High, Low");
							
							// Setting  direction
								
							digitalWrite(MFR_A_PIN, LOW);
							digitalWrite(MFR_B_PIN, HIGH);
							
							digitalWrite(MFL_A_PIN, LOW);
							digitalWrite(MFL_B_PIN, HIGH);
							
							digitalWrite(MBR_A_PIN, LOW);
							digitalWrite(MBR_B_PIN, HIGH);
							
							digitalWrite(MBL_A_PIN, LOW);
							digitalWrite(MBL_B_PIN, HIGH);
							
							// Sending Instruction to start movement
						
							break;
						
						case '0':
							mSpeedFL = 0;
							mSpeedFR = 0;
							
							mSpeedBL = 0;
							mSpeedBR = 0;
							break;
							
						case 'i':
						case 'I':
							Serial.print("INput FL => ");
							while(!Serial.available()); // waits untill serial communcation line is not avalible meaning that data was sent from the opposite host 
							Serial.readBytesUntil('n', pwm, 3);
							
							mSpeedFL = atoi(pwm);
							Serial.println(mSpeedFL);
							
							for(int i = 0; i < 3; i++)
							{
								pwm[i] = ' ';
							}
							
							Serial.print("INput FR => ");
							while(!Serial.available()); // waits untill serial communcation line is not avalible meaning that data was sent from the opposite host 
							Serial.readBytesUntil('n', pwm, 3);
							
							mSpeedFR = atoi(pwm);
							Serial.println(mSpeedFR);
							
							for(int i = 0; i < 3; i++)
							{
								pwm[i] = ' ';
							}
							
							Serial.print("INput BL => ");
							while(!Serial.available()); // waits untill serial communcation line is not avalible meaning that data was sent from the opposite host 
							Serial.readBytesUntil('n', pwm, 3);
							
							mSpeedBL = atoi(pwm);
							Serial.println(mSpeedBL);
							
							for(int i = 0; i < 3; i++)
							{
								pwm[i] = ' ';
							}
							
							Serial.print("INput BR => ");
							while(!Serial.available()); // waits untill serial communcation line is not avalible meaning that data was sent from the opposite host 
							Serial.readBytesUntil('n', pwm, 3);
							
							mSpeedBR = atoi(pwm);
							Serial.println(mSpeedBR);
							
							for(int i = 0; i < 3; i++)
							{
								pwm[i] = ' ';
							}
							
							break;
					}//end switch
					
					analogWrite(MFR_PWM_PIN, mSpeedFR);
					analogWrite(MFL_PWM_PIN, mSpeedFL);
					
					analogWrite(MBR_PWM_PIN, mSpeedBR);
					analogWrite(MBL_PWM_PIN, mSpeedBL);
					
					Serial.print("SpeedFL = ");
					Serial.print(mSpeedFL);
					Serial.print("	");
					Serial.print("SpeedFR = ");
					Serial.println(mSpeedFR);
					
					Serial.print("SpeedBL = ");
					Serial.print(mSpeedBL);
					Serial.print("	");
					Serial.print("SpeedBR = ");
					Serial.println(mSpeedBR);
					
				}//end while
			break;
		} // end Switch

} // end void loop()
