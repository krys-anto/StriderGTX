#define MFR_A_PIN		34   	// FRONT RIGHT MOTOR
#define MFR_B_PIN		36 
#define MFR_PWM_PIN	7 	// PULSE WIDTH MODULATION PIN

#define MFL_A_PIN		48	//FRONT LEFT MOTOR
#define MFL_B_PIN 		46
#define MFL_PWM_PIN	5	 // PULSE WIDTH MODULATION PIN

#define MBR_A_PIN		38	//BACK RIGHT MOTOR
#define MBR_B_PIN		40
#define MBR_PWM_PIN	8	// PULSE WIDTH MODULATION PIN

#define MBL_A_PIN		44	//BACK LEFT MOTOR
#define MBL_B_PIN		42
#define MBL_PWM_PIN	6 	// PULSE WIDTH MODULATION PIN 

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

void loop()
{
	if (Serial.available() > 0) 
	{
		switch(Serial.read())
		{
			case 'F': // Forward Test
				
				Serial.println("Motor Forward Test Low, High");
					
				// Setting  direction 
				
				digitalWrite(MFR_A_PIN, LOW);
				digitalWrite(MFR_B_PIN, HIGH);
				
				digitalWrite(MFL_A_PIN, HIGH);
				digitalWrite(MFL_B_PIN, LOW);
				
				digitalWrite(MBR_A_PIN, LOW);
				digitalWrite(MBR_B_PIN, HIGH);
				
				digitalWrite(MBL_A_PIN, HIGH);
				digitalWrite(MBL_B_PIN, LOW);
				
					// Sending Instruction to start movement
				
				break;
			
			case 'B': // Motor BACKWARD
			
				Serial.println("Motor Forward Test High, Low");
				
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
			
				Serial.println("Motor Forward Test High, Low");
				
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
				mSpeed = 0;
				break;
				
			case '1':
				mSpeed = 25;
				break;
				
			case '2':
				mSpeed = 50;
				break;
				
			case '3':
				mSpeed = 75;
				break;
				
			case '4':
				mSpeed = 100;
				break;
				
			case '5':
				mSpeed = 125;
				break;
				
			case '6':
				mSpeed = 150;
				break;
				
			case '7':
				mSpeed = 175;
				break;
				
			case '8':
				mSpeed = 200;
				break;
				
			case '9':
				mSpeed = 225;
				break;
				
            case 'I':
               	mSpeed += 2;
                break;	
				 
		} // end Switch
		
		Serial.print("Speed = ");
		Serial.println(mSpeed);
		
		analogWrite(MFR_PWM_PIN, mSpeed);
		analogWrite(MFL_PWM_PIN, mSpeed);
		
		analogWrite(MBR_PWM_PIN, mSpeed);
		analogWrite(MBL_PWM_PIN, mSpeed);
	} // end If 
} // end void loop()



