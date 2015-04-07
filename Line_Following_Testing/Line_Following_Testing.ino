/********************************************************************************
*	This code is used to test the paralax Infrared Line Follower		*
*	along with 2 motor contorllers <insert name of motor contorller>	*
*	and 4 motors of the strider GTX.					*
*										*
*	The IRF identifies and returns 0's/1's; 0's				*
*	as white lines and 1's as black surfaces.				*
**********************************************************************************/
//*******************************************//
//    Declaration of Motor Controller PINs   //
//*******************************************//
#define MFR_A_PIN		11  // FRONT RIGHT MOTOR 
#define MFR_B_PIN		12 
#define MFR_PWM_PIN		13 	// PULSE WIDTH MODULATION PIN

#define MFL_A_PIN		5	//FRONT LEFT MOTOR
#define MFL_B_PIN 		6
#define MFL_PWM_PIN		7	// PULSE WIDTH MODULATION PIN

#define MBR_A_PIN		9	//BACK RIGHT MOTOR
#define MBR_B_PIN		10
#define MBR_PWM_PIN		8	// PULSE WIDTH MODULATION PIN

#define MBL_A_PIN		3	//BACK LEFT MOTOR
#define MBL_B_PIN		4
#define MBL_PWM_PIN		2 	// PULSE WIDTH MODULATION PIN 

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

int x = 110;

//***********************************************//
//    Stetting up peripherals to run code once   //
//***********************************************//
void setup()
{
	Serial.begin(9600);  			// set up serial port class to establish communicaltion OUTput and INput
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
	
	Serial.println("Ramp");
	digitalWrite(MFR_A_PIN, LOW);
	digitalWrite(MFR_B_PIN, HIGH);
	
	digitalWrite(MFL_A_PIN, LOW);
	digitalWrite(MFL_B_PIN, HIGH);
	
	digitalWrite(MBR_A_PIN, HIGH);
	digitalWrite(MBR_B_PIN, LOW);
	
	digitalWrite(MBL_A_PIN, LOW);
	digitalWrite(MBL_B_PIN, HIGH);
	
	for(int i = 100; i < 120; i += 2)
	{
		analogWrite(MFR_PWM_PIN, i);
		analogWrite(MFL_PWM_PIN, i);
		
		analogWrite(MBR_PWM_PIN, i);
		analogWrite(MBL_PWM_PIN, i);
		delay(50);
	}	
	for(int i = 120; i > x; i -= 2)
	{
		analogWrite(MFR_PWM_PIN, i);
		analogWrite(MFL_PWM_PIN, i);
		
		analogWrite(MBR_PWM_PIN, i);
		analogWrite(MBL_PWM_PIN, i);
		delay(50);
	}
}

int IRL_in;					// declaration of the buffer to store the output of all  s0- s7 pins of the KRF

int mSpeedFR = 0;
int mSpeedBR = 0;

int mSpeedFL = 0;
int mSpeedBL = 0;

char pwm[] = {' ', ' ', ' '};

void loop()
{
	IRL_in = 0;
	
	for(int i = 0; i <= 7; i++)
	{
		IRL_in = (IRL_in << 1) + digitalRead(IRL_PIN_s7 - i);
	}
	Serial.println(IRL_in, BIN);
	
	switch(IRL_in)
	{
		//Sensor conditions that indicate that the line is at the center
		case 0b11000011:
		case 0b11100011:
		case 0b11000111:
			Serial.println("00L00");
			digitalWrite(MFR_A_PIN, LOW);
			digitalWrite(MFR_B_PIN, HIGH);
			
			digitalWrite(MFL_A_PIN, LOW);
			digitalWrite(MFL_B_PIN, HIGH);
			
			digitalWrite(MBR_A_PIN, HIGH);
			digitalWrite(MBR_B_PIN, LOW);
			
			digitalWrite(MBL_A_PIN, LOW);
			digitalWrite(MBL_B_PIN, HIGH);
			
			analogWrite(MFR_PWM_PIN, x);
			analogWrite(MFL_PWM_PIN, x);
			
			analogWrite(MBR_PWM_PIN, x);
			analogWrite(MBL_PWM_PIN, x);
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
			
			analogWrite(MFR_PWM_PIN, x + 40);
			analogWrite(MFL_PWM_PIN, x);
			
			analogWrite(MBR_PWM_PIN, x + 40);
			analogWrite(MBL_PWM_PIN, x);
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
			
			analogWrite(MFR_PWM_PIN, x + 20);
			analogWrite(MFL_PWM_PIN, x);
			
			analogWrite(MBR_PWM_PIN, x + 20);
			analogWrite(MBL_PWM_PIN, x);
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
			
			analogWrite(MFR_PWM_PIN, x);
			analogWrite(MFL_PWM_PIN, x + 40);
			
			analogWrite(MBR_PWM_PIN, x);
			analogWrite(MBL_PWM_PIN, x + 40);
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
			
			analogWrite(MFR_PWM_PIN, x);
			analogWrite(MFL_PWM_PIN, x + 20);
			
			analogWrite(MBR_PWM_PIN, x);
			analogWrite(MBL_PWM_PIN, x + 20);
			break;
			
		case 0b00111111:
		case 0b01111111:
			Serial.println("L0000");
			digitalWrite(MFR_A_PIN, LOW);
			digitalWrite(MFR_B_PIN, HIGH);
			
			digitalWrite(MFL_A_PIN, HIGH);
			digitalWrite(MFL_B_PIN, LOW);
			
			digitalWrite(MBR_A_PIN, HIGH);
			digitalWrite(MBR_B_PIN, LOW);
			
			digitalWrite(MBL_A_PIN, HIGH);
			digitalWrite(MBL_B_PIN, LOW);
			
			analogWrite(MFR_PWM_PIN, x);
			analogWrite(MFL_PWM_PIN, x);
			
			analogWrite(MBR_PWM_PIN, x);
			analogWrite(MBL_PWM_PIN, x);
			break;
		case 0b11111100:
		case 0b11111110:
			Serial.println("0000L");
			digitalWrite(MFR_A_PIN, HIGH);
			digitalWrite(MFR_B_PIN, LOW);
			
			digitalWrite(MFL_A_PIN, LOW);
			digitalWrite(MFL_B_PIN, HIGH);
			
			digitalWrite(MBR_A_PIN, LOW);
			digitalWrite(MBR_B_PIN, HIGH);
			
			digitalWrite(MBL_A_PIN, LOW);
			digitalWrite(MBL_B_PIN, HIGH);
			
			analogWrite(MFR_PWM_PIN, x);
			analogWrite(MFL_PWM_PIN, x);
			
			analogWrite(MBR_PWM_PIN, x);
			analogWrite(MBL_PWM_PIN, x);
			break;
		default:
			Serial.println("Default Error");
            	break;
	}
}

