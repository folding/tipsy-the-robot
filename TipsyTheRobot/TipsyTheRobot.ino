#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"
#include "Car.h"

enum InputAction
{
	Forward,
	Reverse,
	WideLeft,
	WideRight,
	UeeeLeft,
	UeeeRight,
	Stop
};

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);

Car *tipsy = new Car(myMotor, myOtherMotor);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  tipsy->Start();

  pinMode(13, OUTPUT);

  delay(2000);
}

uint8_t inputs[6] = { Forward, Reverse, Forward, WideLeft, Forward,WideRight };
uint8_t commandNumber = 0;
uint16_t loopTimer = 0;
void loop() {

	if (!tipsy->Accelerating())
	{
		//hard code the inputs for now...
		commandNumber++;
		if (commandNumber > 5)
		{
			commandNumber = 0;
		}

		//collect inputs
		InputAction a = (InputAction)inputs[commandNumber];

		//blink our led so we know what's going on
		if (commandNumber % 2 == 0)
		{
			digitalWrite(13, HIGH);
		}
		else
		{
			digitalWrite(13, LOW);
		}

		//tell car what to do based on inputs
		switch (a)
		{
		case Forward:
			tipsy->DriveForward();
			break;
		case Reverse:
			tipsy->DriveBackward();
			break;
		case WideLeft:
			tipsy->WideLeft();
			break;
		case WideRight:
			tipsy->WideRight();
			break;
		case UeeeLeft:
			tipsy->UeeeLeft();
			break;
		case UeeeRight:
			tipsy->UeeeRight();
			break;
		case Stop:
			tipsy->Stop();
			break;
		default:
			break;
		}
	}

	//tell car to run
	tipsy->Run();

	tipsy->Wait();

}