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
	void DriveForward(int driveTime);
	void DriveBackward(int driveTime);
	void WideRight(int driveTime);
	void WideLeft(int driveTime);
	void Wait();
	~Car();
};

