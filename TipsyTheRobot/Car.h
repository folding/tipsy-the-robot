#pragma once

#include <Adafruit_MotorShield.h>

class Car
{
public:
	Car(Adafruit_DCMotor *left, Adafruit_DCMotor *right);
	void Start();
	void TurnRight90();
	void TurnLeft90();
	void UeeeRight();
	void UeeeLeft();
	void DriveForward();
	void DriveBackward();
	void Wait();
	~Car();
};

