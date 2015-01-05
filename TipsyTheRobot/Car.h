#pragma once

#include <Adafruit_MotorShield.h>

class Car
{
public:
	Car(Adafruit_DCMotor *left, Adafruit_DCMotor *right);
	void Start();
	void DriveForward();
	void DriveBackward();
	void WideRight();
	void WideLeft();
	void UeeeRight();
	void UeeeLeft();
	void Stop();
	void Run();
	void Wait();
	bool Accelerating();
	~Car();
};

