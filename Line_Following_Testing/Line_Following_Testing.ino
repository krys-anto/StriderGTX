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
#define MFR_A_PIN		37  // FRONT RIGHT MOTOR 
#define MFR_B_PIN		39 
#define MFR_PWM_PIN		5 	// PULSE WIDTH MODULATION PIN

#define MFL_A_PIN		34	//FRONT LEFT MOTOR
#define MFL_B_PIN 		32
#define MFL_PWM_PIN		3	// PULSE WIDTH MODULATION PIN

#define MBR_A_PIN		33	//BACK RIGHT MOTOR
#define MBR_B_PIN		35
#define MBR_PWM_PIN		4	// PULSE WIDTH MODULATION PIN

#define MBL_A_PIN		38	//BACK LEFT MOTOR
#define MBL_B_PIN		36
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
	pinMode(IRL_PIN_s7, INPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	
}

int IRL_in;					// declaration of the buffer to store the output of all  s0- s7 pins of the KRF
int diff = 0;					// decalaration of the variablediff; is used for the variation of the turning value.  
int mPower = map(50, 0, 100, 80, 190);

void loop()
{
	IRL_in = 0;
	
	for(int i = 0; i <= 7; i++)
	{
		IRL_in = (IRL_in << 1) + digitalRead(IRL_PIN_s7 - i);
		Serial.println(IRL_in, BIN);
	}
	Serial.println(IRL_in, BIN);
	
	switch(IRL_in)
	{
		case 0b00111111:
		case 0b00011111:

			Serial.println("L0000");
			
			digitalWrite(MFR_A_PIN, HIGH);
			digitalWrite(MFR_B_PIN, LOW);
			
			digitalWrite(MBR_A_PIN, HIGH);
			digitalWrite(MBR_B_PIN, LOW);
		
			digitalWrite(MFL_A_PIN, LOW);
			digitalWrite(MFL_B_PIN, HIGH);
		
			digitalWrite(MBL_A_PIN, LOW);
			digitalWrite(MBL_B_PIN, HIGH);
		
			analogWrite(MFR_PWM_PIN, mPower);
			analogWrite(MFL_PWM_PIN, mPower);
			
			analogWrite(MBR_PWM_PIN, mPower);
			analogWrite(MBL_PWM_PIN, mPower);
			break;
		case 0b00011111:
		case 0b10001111:
			
			Serial.println("LL000");
			
			diff = 20;
			
			digitalWrite(MFR_A_PIN, HIGH);
			digitalWrite(MFR_B_PIN, LOW);
			
			digitalWrite(MBR_A_PIN, HIGH);
			digitalWrite(MBR_B_PIN, LOW);
		
			digitalWrite(MFL_A_PIN, LOW);
			digitalWrite(MFL_B_PIN, HIGH);
		
			digitalWrite(MBL_A_PIN, LOW);
			digitalWrite(MBL_B_PIN, HIGH); 
			
			analogWrite(MFR_PWM_PIN, mPower - diff);
			analogWrite(MFL_PWM_PIN, mPower);
			
			analogWrite(MBR_PWM_PIN, mPower - diff);
			analogWrite(MBL_PWM_PIN, mPower);
			break;
			
		case 0b11000111:
                        Serial.println("0LL00");
		
			diff = 20;
			
			digitalWrite(MFR_A_PIN, HIGH);
			digitalWrite(MFR_B_PIN, LOW);
			
			digitalWrite(MBR_A_PIN, HIGH);
			digitalWrite(MBR_B_PIN, LOW);
						
			digitalWrite(MFL_A_PIN, HIGH);
			digitalWrite(MFL_B_PIN, LOW);
				
			digitalWrite(MBL_A_PIN, HIGH);
			digitalWrite(MBL_B_PIN, LOW);
		
			analogWrite(MFR_PWM_PIN, mPower - diff);
			analogWrite(MFL_PWM_PIN, mPower);
			
			analogWrite(MBR_PWM_PIN, mPower - diff);
			analogWrite(MBL_PWM_PIN, mPower);
			break;
		case 0b11100111:

                        Serial.println("00L00");
                        
                        digitalWrite(MFR_A_PIN, HIGH);
			digitalWrite(MFR_B_PIN, LOW);
			
			digitalWrite(MBR_A_PIN, HIGH);
			digitalWrite(MBR_B_PIN, LOW);
						
			digitalWrite(MFL_A_PIN, HIGH);
			digitalWrite(MFL_B_PIN, LOW);
				
			digitalWrite(MBL_A_PIN, HIGH);
			digitalWrite(MBL_B_PIN, LOW);
		
			analogWrite(MFR_PWM_PIN, mPower);
			analogWrite(MFL_PWM_PIN, mPower);
			
			analogWrite(MBR_PWM_PIN, mPower);
			analogWrite(MBL_PWM_PIN, mPower);
			break;
		case 0b11100011:
		
			Serial.println("00LL0");
			
			diff = 20;
			
			digitalWrite(MFR_A_PIN, HIGH);
			digitalWrite(MFR_B_PIN, LOW);
			
			digitalWrite(MBR_A_PIN, HIGH);
			digitalWrite(MBR_B_PIN, LOW);
						
			digitalWrite(MFL_A_PIN, HIGH);
			digitalWrite(MFL_B_PIN, LOW);
				
			digitalWrite(MBL_A_PIN, HIGH);
			digitalWrite(MBL_B_PIN, LOW);
		
			analogWrite(MFR_PWM_PIN, mPower);
			analogWrite(MFL_PWM_PIN, mPower - diff);
			
			analogWrite(MBR_PWM_PIN, mPower);
			analogWrite(MBL_PWM_PIN, mPower - diff);
			break;
		case 0b11110011:
		
			Serial.println("000L0");
			
			diff = 50;
			
			digitalWrite(MFR_A_PIN, HIGH);
			digitalWrite(MFR_B_PIN, LOW);
			
			digitalWrite(MBR_A_PIN, HIGH);
			digitalWrite(MBR_B_PIN, LOW);
						
			digitalWrite(MFL_A_PIN, HIGH);
			digitalWrite(MFL_B_PIN, LOW);
				
			digitalWrite(MBL_A_PIN, HIGH);
			digitalWrite(MBL_B_PIN, LOW);
			
			analogWrite(MFR_PWM_PIN, mPower);
			analogWrite(MFL_PWM_PIN, mPower);
			
			analogWrite(MBR_PWM_PIN, mPower);
			analogWrite(MBL_PWM_PIN, mPower);
			break;
		case 0b11111001:
		case 0b11110001:
			
			Serial.println("000LL");
		
			diff = 20;
			
			digitalWrite(MFR_A_PIN, LOW);
			digitalWrite(MFR_B_PIN, HIGH);
	
			digitalWrite(MBR_A_PIN, LOW);
			digitalWrite(MBR_B_PIN, HIGH);
			
			digitalWrite(MFL_A_PIN, HIGH);
			digitalWrite(MFL_B_PIN, LOW);
				
			digitalWrite(MBL_A_PIN, HIGH);
			digitalWrite(MBL_B_PIN, LOW);
			
			analogWrite(MFR_PWM_PIN, mPower);
			analogWrite(MFL_PWM_PIN, mPower - diff);
			
			analogWrite(MBR_PWM_PIN, mPower);
			analogWrite(MBL_PWM_PIN, mPower - diff);
			break;
		case 0b11111100:
		case 0b11111000:
		
			Serial.println("0000L");
		
			digitalWrite(MFR_A_PIN, LOW);
			digitalWrite(MFR_B_PIN, HIGH);
	
			digitalWrite(MBR_A_PIN, LOW);
			digitalWrite(MBR_B_PIN, HIGH);
			
			digitalWrite(MFL_A_PIN, HIGH);
			digitalWrite(MFL_B_PIN, LOW);
				
			digitalWrite(MBL_A_PIN, HIGH);
			digitalWrite(MBL_B_PIN, LOW);
			
			analogWrite(MFR_PWM_PIN, mPower);
			analogWrite(MFL_PWM_PIN, mPower);
			
			analogWrite(MBR_PWM_PIN, mPower);
			analogWrite(MBL_PWM_PIN, mPower);
			break;
		case 0b00001111:
		case 0b00000111:
			
			Serial.println("LLL00");
			
			analogWrite(MFR_PWM_PIN, mPower);
			analogWrite(MFL_PWM_PIN, mPower);
			
			analogWrite(MBR_PWM_PIN, mPower);
			analogWrite(MBL_PWM_PIN, mPower);
			break;
		case 0b11110000:
		case 0b11100000:
			
			Serial.println("00LLL");
		
			analogWrite(MFR_PWM_PIN, mPower);
			analogWrite(MFL_PWM_PIN, mPower);
			
			analogWrite(MBR_PWM_PIN, mPower);
			analogWrite(MBL_PWM_PIN, mPower);
			break;
			
		default:
		
			Serial.println("Default Error");
			
			analogWrite(MFR_PWM_PIN, 0);
			analogWrite(MFL_PWM_PIN, 0);
			
			analogWrite(MBR_PWM_PIN, 0);
			analogWrite(MBL_PWM_PIN, 0);
            	break;
	}
}

