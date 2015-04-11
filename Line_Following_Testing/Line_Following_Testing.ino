#include <Servo.h>

/********************************************************************************
*	This code is used to test the paralax Infrared Line Follower		*
*	along with 2 motor contorllers <insert name of motor contorller>	*
*	and 4 motors of the strider GTX.					*
*										*
*	The IRF identifies and returns 0's/1's; 0's				*
*	as white lines and 1's as black surfaces.				*
**********************************************************************************/
// Right Arm
#define R_ARM1_PIN 		42
#define R_ARM2_PIN 		44
#define R_ARM3_PIN 		46
#define R_ARM4_PIN 		48
#define R_ARM5_PIN 		50
#define R_ARMC_PIN 		52

// Left Arm
#define L_ARM1_PIN 		43
#define L_ARM2_PIN 		45
#define L_ARM3_PIN 		47
#define L_ARM4_PIN 		49
#define L_ARM5_PIN 		51
#define L_ARMC_PIN 		53

//**************************************//
//	Remote Start Declaration	//
//**************************************//
#define LDR_PIN		0

//**************************************//
//      Servo Object Declaration     	//
//**************************************//

// Right Arm
Servo rArm_Servo1;
Servo rArm_Servo2;
Servo rArm_Servo3;
Servo rArm_Servo4;
Servo rArm_Servo5;
Servo rClaw;

// Left Arm
Servo lArm_Servo1;
Servo lArm_Servo2;
Servo lArm_Servo3;
Servo lArm_Servo4;
Servo lArm_Servo5;
Servo lClaw;


//*******************************************//
//    Declaration of Motor Controller PINs   //
//*******************************************//
#define MFR_A_PIN	11  // FRONT RIGHT MOTOR 
#define MFR_B_PIN	12 
#define MFR_PWM_PIN	13 	// PULSE WIDTH MODULATION PIN

#define MFL_A_PIN	5	//FRONT LEFT MOTOR
#define MFL_B_PIN 	6
#define MFL_PWM_PIN	7	// PULSE WIDTH MODULATION PIN

#define MBR_A_PIN	9	//BACK RIGHT MOTOR
#define MBR_B_PIN	10
#define MBR_PWM_PIN	8	// PULSE WIDTH MODULATION PIN

#define MBL_A_PIN	3	//BACK LEFT MOTOR
#define MBL_B_PIN	4
#define MBL_PWM_PIN	2 	// PULSE WIDTH MODULATION PIN 

//**************************************//
//      Declaration of the IRF PINs     //
//**************************************//
#define IRL_PIN_s0	22
#define IRL_PIN_s1	23
#define IRL_PIN_s2	24
#define IRL_PIN_s3	25
#define IRL_PIN_s4	26
#define IRL_PIN_s5	27
#define IRL_PIN_s6	28
#define IRL_PIN_s7	29
#define IRL_PIN_EN	30

int xFR = 147;
int xFL = 157;
int xBR = 130;
int xBL = 130;


/*
void Stop_Motors(void);
void IRL_Read(void);
void Forward_Motors(void);
*/

//***********************************************//
//    Stetting up peripherals to run code once   //
//***********************************************//
void setup()
{
	Serial.begin(9600); //Opens serial connection at 9600 baud rate
	
	//*****************************//
	//    Setting up Motor PINs    //
	//*****************************//
	pinMode(MFR_A_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(MFR_B_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(MFR_PWM_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	
	// Motor Front Left Side
	pinMode(MFL_A_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(MFL_B_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(MFL_PWM_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	 
	// Motor Back Right Side
	pinMode(MBR_A_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(MBR_B_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(MBR_PWM_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	
	// Motor Back Left Side
	pinMode(MBL_A_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(MBL_B_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(MBL_PWM_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output

	pinMode(IRL_PIN_s0, INPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(IRL_PIN_s1, INPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(IRL_PIN_s3, INPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(IRL_PIN_s4, INPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(IRL_PIN_s5, INPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(IRL_PIN_s6, INPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(IRL_PIN_s7, INPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as outpu
	pinMode(IRL_PIN_EN, OUTPUT);
	
	digitalWrite(IRL_PIN_EN, HIGH);;
	
	//Initaizing Robotic Right Arm Angles
	rArm_Servo1.write(150);
	rArm_Servo2.write(170);
	rArm_Servo3.write(180);
	rArm_Servo4.write(180);
	rArm_Servo5.write(180);
	
	//Initiaizing Robotic Left Arm Angles
	lArm_Servo1.write(10);
	lArm_Servo2.write(5);
	lArm_Servo3.write(5);
	lArm_Servo4.write(5);
	lArm_Servo5.write(5);
	
	//Initiaizng Heavy Arm Claw to hold position.
	lClaw.writeMicroseconds(1500);
	
	rArm_Servo1.attach(R_ARM1_PIN); // Attaches(inputs the pin out to the Servo object) class) the servos to their respective pin	
	rArm_Servo2.attach(R_ARM2_PIN);	// Attaches(inputs the pin out to the Servo object) class) the servos to their respective pin
	rArm_Servo3.attach(R_ARM3_PIN);	// Attaches(inputs the pin out to the Servo object) class) the servos to their respective pin
	rArm_Servo4.attach(R_ARM4_PIN);	// Attaches(inputs the pin out to the Servo object) class) the servos to their respective pin
	//rArm_Servo5.attach(R_ARM5_PIN);	// Attaches(inputs the pin out to the Servo object) class) the servos to their respective pin
	//rClaw.attach(R_ARMC_PIN);	// Attaches(inputs the pin out to the Servo object) class) the servos to their respective pin
	
	lArm_Servo1.attach(L_ARM1_PIN); // Attaches(inputs the pin out to the Servo object) class) the servos to their respective pin
	lArm_Servo2.attach(L_ARM2_PIN);	// Attaches(inputs the pin out to the Servo object) class) the servos to their respective pin
	lArm_Servo3.attach(L_ARM3_PIN);	// Attaches(inputs the pin out to the Servo object) class) the servos to their respective pin
	lArm_Servo4.attach(L_ARM4_PIN);	// Attaches(inputs the pin out to the Servo object) class) the servos to their respective pin
	//lArm_Servo5.attach(L_ARM5_PIN);	// Attaches(inputs the pin out to the Servo object) class) the servos to their respective pin
	lClaw.attach(L_ARMC_PIN);	// Attaches(inputs the pin out to the Servo object) class) the servos to their respective pin
	
	Serial.println("Ramp");
	digitalWrite(MFR_A_PIN, LOW);
	digitalWrite(MFR_B_PIN, HIGH);
	
	digitalWrite(MFL_A_PIN, LOW);
	digitalWrite(MFL_B_PIN, HIGH);
	
	digitalWrite(MBR_A_PIN, HIGH);
	digitalWrite(MBR_B_PIN, LOW);
	
	digitalWrite(MBL_A_PIN, LOW);
	digitalWrite(MBL_B_PIN, HIGH);

	for(int i = 0; i < 40; i += 2)
	{
		analogWrite(MFR_PWM_PIN, xFR + i);
		analogWrite(MFL_PWM_PIN, xFL + i);
		
		analogWrite(MBR_PWM_PIN, xBR + i);
		analogWrite(MBL_PWM_PIN, xBR + i);
		delay(50);
	}
	
	delay(1000);
	/*
	for(int i = 30; i >  ; i -= 1)
	{
		analogWrite(MFR_PWM_PIN, xFR + i);
		analogWrite(MFL_PWM_PIN, xFL + i);
		
		analogWrite(MBR_PWM_PIN, xBR + i);
		analogWrite(MBL_PWM_PIN, xBL + i);
		delay(50);
	}
	*/
}

int IRL_in;					// declaration of the buffer to store the output of all  s0- s7 pins of the KRF
int game_count = 0;

char pwm[] = {' ', ' ', ' '};

void loop()IRL_Read();
	
	switch(IRL_in)
	{
		//Sensor conditions that indicate that the line is at the center
		case 0b11000011:
		case 0b11100011:
		case 0b11000111:
			Serial.println("00L00");
			Forward_Motors();
			break;
			
		case 0b10000111:
		case 0b00001111:
			Serial.println("0L000");
			digitalWrite(MFR_A_PIN, LOW);
			digitalWrite(MFR_B_PIN, HIGH);
			
			digitalWrite(MFL_A_PIN, LOW);
			digitalWrite(MFL_B_PIN, HIGH);
			
			digitalWrite(MBR_A_PIN, HIGH);
			digitalWrite(MBR_B_PIN, LOW);
			
			digitalWrite(MBL_A_PIN, LOW);
			digitalWrite(MBL_B_PIN, HIGH);
			
			analogWrite(MFR_PWM_PIN, xFR + 60);
			analogWrite(MFL_PWM_PIN, xFL - 30);
		
			analogWrite(MBR_PWM_PIN, xBR + 60);
			analogWrite(MBL_PWM_PIN, xBL - 30);
			break;
			
		case 0b10001111:
		case 0b00011111:
			Serial.println("0LL00");
			digitalWrite(MFR_A_PIN, LOW);
			digitalWrite(MFR_B_PIN, HIGH);
			
			digitalWrite(MFL_A_PIN, LOW);
			digitalWrite(MFL_B_PIN, HIGH);
			
			digitalWrite(MBR_A_PIN, HIGH);
			digitalWrite(MBR_B_PIN, LOW);
			
			digitalWrite(MBL_A_PIN, LOW);
			digitalWrite(MBL_B_PIN, HIGH);
			
			analogWrite(MFR_PWM_PIN, xFR + 40);
			analogWrite(MFL_PWM_PIN, xFL - 30);
			
			analogWrite(MBR_PWM_PIN, xBR + 40);
			analogWrite(MBL_PWM_PIN, xBL - 30);
			break;
			
		case 0b11100001:
		case 0b11110000:
			
			Serial.println("00LL0");
			digitalWrite(MFR_A_PIN, LOW);
			digitalWrite(MFR_B_PIN, HIGH);
			
			digitalWrite(MFL_A_PIN, LOW);
			digitalWrite(MFL_B_PIN, HIGH);
			
			digitalWrite(MBR_A_PIN, HIGH);
			digitalWrite(MBR_B_PIN, LOW);
			
			digitalWrite(MBL_A_PIN, LOW);
			digitalWrite(MBL_B_PIN, HIGH);
			
			analogWrite(MFR_PWM_PIN, xFR - 30);
			analogWrite(MFL_PWM_PIN, xFL + 60);
			
			analogWrite(MBR_PWM_PIN, xBR - 30);
			analogWrite(MBL_PWM_PIN, xBL + 60);
			break;
			
		case 0b11110001:
		case 0b11111000:
			Serial.println("000L0");
			digitalWrite(MFR_A_PIN, LOW);
			digitalWrite(MFR_B_PIN, HIGH);
			
			digitalWrite(MFL_A_PIN, LOW);
			digitalWrite(MFL_B_PIN, HIGH);
			
			digitalWrite(MBR_A_PIN, HIGH);
			digitalWrite(MBR_B_PIN, LOW);
			
			digitalWrite(MBL_A_PIN, LOW);
			digitalWrite(MBL_B_PIN, HIGH);
			
			analogWrite(MFR_PWM_PIN, xFR - 30);
			analogWrite(MFL_PWM_PIN, xFL + 40);
			
			analogWrite(MBR_PWM_PIN, xBR - 30);
			analogWrite(MBL_PWM_PIN, xBL + 40);
			break;
			
		case 0b00111111:
		case 0b01111111:
			Serial.println("L0000");
			/*
			digitalWrite(MFR_A_PIN, LOW);
			digitalWrite(MFR_B_PIN, HIGH);
			
			digitalWrite(MFL_A_PIN, HIGH);
			digitalWrite(MFL_B_PIN, LOW);
			
			digitalWrite(MBR_A_PIN, HIGH);
			digitalWrite(MBR_B_PIN, LOW);
			
			digitalWrite(MBL_A_PIN, HIGH);
			digitalWrite(MBL_B_PIN, LOW);
			
			analogWrite(MFR_PWM_PIN, xFR);
			analogWrite(MFL_PWM_PIN, xFL);
			
			analogWrite(MBR_PWM_PIN, xBR);
			analogWrite(MBL_PWM_PIN, xBL);
			*/
			
			digitalWrite(MFR_A_PIN, LOW);
			digitalWrite(MFR_B_PIN, HIGH);
			
			digitalWrite(MFL_A_PIN, LOW);
			digitalWrite(MFL_B_PIN, HIGH);
			
			digitalWrite(MBR_A_PIN, HIGH);
			digitalWrite(MBR_B_PIN, LOW);
			
			digitalWrite(MBL_A_PIN, LOW);
			digitalWrite(MBL_B_PIN, HIGH);
			
			analogWrite(MFR_PWM_PIN, 255);
			analogWrite(MFL_PWM_PIN, 0);
			
			analogWrite(MBR_PWM_PIN, 255);
			analogWrite(MBL_PWM_PIN, 0);
			
			
			break;
		case 0b11111100:
		case 0b11111110:
			Serial.println("0000L");
			/*
			digitalWrite(MFR_A_PIN, HIGH);
			digitalWrite(MFR_B_PIN, LOW);
			
			digitalWrite(MFL_A_PIN, LOW);
			digitalWrite(MFL_B_PIN, HIGH);
			
			digitalWrite(MBR_A_PIN, LOW);
			digitalWrite(MBR_B_PIN, HIGH);
			
			digitalWrite(MBL_A_PIN, LOW);
			digitalWrite(MBL_B_PIN, HIGH);
			
			analogWrite(MFR_PWM_PIN, xFR);
			analogWrite(MFL_PWM_PIN, xFL);
			
			analogWrite(MBR_PWM_PIN, xBR);
			analogWrite(MBL_PWM_PIN, xBL);
			*/
			digitalWrite(MFR_A_PIN, LOW);
			digitalWrite(MFR_B_PIN, HIGH);
			
			digitalWrite(MFL_A_PIN, LOW);
			digitalWrite(MFL_B_PIN, HIGH);
			
			digitalWrite(MBR_A_PIN, HIGH);
			digitalWrite(MBR_B_PIN, LOW);
			
			digitalWrite(MBL_A_PIN, LOW);
			digitalWrite(MBL_B_PIN, HIGH);
			
			analogWrite(MFR_PWM_PIN, 0);
			analogWrite(MFL_PWM_PIN, 255);
			
			analogWrite(MBR_PWM_PIN, 0);
			analogWrite(MBL_PWM_PIN, 255);
			break;
		case 0b11111111:
			Serial.println("00000");
			Stop_Motors();
			break;
		case 0b00000000:
		
			Serial.println("LLLLL");
			
			Stop_Motors();
			
			switch(game_count)
			{
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
			}
		/*
			Stop_Motors();
			Forward_Motors();
			
			delay(250);
			
			Stop_Motors();
			do
			{
				Turn_Left_Motors(30);
				IRL_Read();
			}while(IRL_in != 11000011 || IRL_in != 11000111 || IRL_in != 11100011);
			Serial.println("STOP AFTER WHILE");
			Stop_Motors();
		*/
			break;
		case 0b00000111:
		case 0b00000011:
		case 0b00000001:
			Serial.println("LLL00/LLLL0");
			Stop_Motors();
			Forward_Motors();
			
			delay(250);
			
			Stop_Motors();
			Turn_Left_Motors(0);
			delay(250);
			while(IRL_in != 11000111 || IRL_in != 11000011 || IRL_in != 11100011 || IRL_in != 10000111 || IRL_in != 11100001)
			{
				IRL_Read();
			}
			Serial.println("STOP AFTER WHILE");
			Stop_Motors();
			while(1);
			break;
		case 0b11100000:
		case 0b11000000:
		case 0b10000000:
			Serial.println("LLL00/LLLL0");
			Stop_Motors();
			Forward_Motors();
			
			delay(250);
			
			Stop_Motors();
			Turn_Right_Motors(0);
			while(IRL_in != 11000111 || IRL_in != 11000011 || IRL_in != 11100011 || IRL_in != 10000111 || IRL_in != 11100001)
			{
				IRL_Read();
			}
			
			Serial.println("STOP AFTER WHILE");
			Stop_Motors();
			while(1);
			break;
		default:
			Serial.println("Default Error");
            	break;
	}
{
	
}

void Stop_Motors(void)
{
	Serial.println("Stop");
	analogWrite(MFR_PWM_PIN, 0);
	analogWrite(MFL_PWM_PIN, 0);
			
	analogWrite(MBR_PWM_PIN, 0);
	analogWrite(MBL_PWM_PIN, 0);
}

void IRL_Read(void)
{
	IRL_in = 0;
	
	for(int i = 0; i <= 7; i++)
	{
		IRL_in = (IRL_in << 1) + digitalRead(IRL_PIN_s7 - i);
	}
	Serial.println(IRL_in, BIN);
}

void Forward_Motors(void)
{
	Serial.println("Forward");
	digitalWrite(MFR_A_PIN, LOW);
	digitalWrite(MFR_B_PIN, HIGH);
	
	digitalWrite(MFL_A_PIN, LOW);
	digitalWrite(MFL_B_PIN, HIGH);
	
	digitalWrite(MBR_A_PIN, HIGH);
	digitalWrite(MBR_B_PIN, LOW);
	
	digitalWrite(MBL_A_PIN, LOW);
	digitalWrite(MBL_B_PIN, HIGH);
	
	analogWrite(MFR_PWM_PIN, xFR);
	analogWrite(MFL_PWM_PIN, xFL);
	
	analogWrite(MBR_PWM_PIN, xBR);
	analogWrite(MBL_PWM_PIN, xBL);
}

void Forward_Motors(int i)
{
	Serial.println("Forward+");
	digitalWrite(MFR_A_PIN, LOW);
	digitalWrite(MFR_B_PIN, HIGH);
	
	digitalWrite(MFL_A_PIN, LOW);
	digitalWrite(MFL_B_PIN, HIGH);
	
	digitalWrite(MBR_A_PIN, HIGH);
	digitalWrite(MBR_B_PIN, LOW);
	
	digitalWrite(MBL_A_PIN, LOW);
	digitalWrite(MBL_B_PIN, HIGH);
	
	analogWrite(MFR_PWM_PIN, xFR + i);
	analogWrite(MFL_PWM_PIN, xFL + i);
	
	analogWrite(MBR_PWM_PIN, xBR + i);
	analogWrite(MBL_PWM_PIN, xBL + i);
}

void Turn_Left_Motors(int i)
{
	Serial.println("Left");
	digitalWrite(MFR_A_PIN, LOW);
	digitalWrite(MFR_B_PIN, HIGH);
	
	digitalWrite(MFL_A_PIN, HIGH);
	digitalWrite(MFL_B_PIN, LOW);
	
	digitalWrite(MBR_A_PIN, HIGH);
	digitalWrite(MBR_B_PIN, LOW);
	
	digitalWrite(MBL_A_PIN, HIGH);
	digitalWrite(MBL_B_PIN, LOW);
	
	analogWrite(MFR_PWM_PIN, xFR + i);
	analogWrite(MFL_PWM_PIN, xFL + i);
	
	analogWrite(MBR_PWM_PIN, xBR + i);
	analogWrite(MBL_PWM_PIN, xBL + i);
}

void Turn_Right_Motors(int i)
{
	Serial.println("Left");
	digitalWrite(MFR_A_PIN, HIGH);
	digitalWrite(MFR_B_PIN, LOW);
	
	digitalWrite(MFL_A_PIN, LOW);
	digitalWrite(MFL_B_PIN, HIGH);
	
	digitalWrite(MBR_A_PIN, LOW);
	digitalWrite(MBR_B_PIN, HIGH);
	
	digitalWrite(MBL_A_PIN, LOW);
	digitalWrite(MBL_B_PIN, HIGH);
	
	analogWrite(MFR_PWM_PIN, xFR + i);
	analogWrite(MFL_PWM_PIN, xFL + i);
	
	analogWrite(MBR_PWM_PIN, xBR + i);
	analogWrite(MBL_PWM_PIN, xBL + i);
}
