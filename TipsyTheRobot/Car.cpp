#include "Car.h"

#define PEAK_TURN_SPEED 240
#define TURN_DELAY 5

#define PEAK_DRIVE_SPEED 255
#define DRIVE_DELAY 8

#define WIDE_TURN_DELAY 15

Adafruit_DCMotor *_left;
Adafruit_DCMotor *_right;
uint8_t i;
uint8_t _leftSpeed = 0;
uint8_t _rightSpeed = 0;

Car::Car(Adafruit_DCMotor *left, Adafruit_DCMotor *right)
{
	_left = left;
	_right = right;
}

void Car::Start()
{
	// Set the speed to start, from 0 (off) to 255 (max speed)
	_left->setSpeed(150);
	_left->run(FORWARD);
	// turn on motor
	_left->run(RELEASE);

	// Set the speed to start, from 0 (off) to 255 (max speed)
	_right->setSpeed(150);
	_right->run(FORWARD);
	// turn on motor
	_right->run(RELEASE);
}

void Car::TurnRight90()
{
	_right->run(BACKWARD);
	_left->run(FORWARD);
	for (i = 0; i<PEAK_TURN_SPEED; i++) {
		_left->setSpeed(i);
		_right->setSpeed(i);
		delay(TURN_DELAY);
	}
	for (i = PEAK_TURN_SPEED; i != 0; i--) {
		_left->setSpeed(i);
		_right->setSpeed(i);
		delay(TURN_DELAY);
	}
}

void Car::TurnLeft90()
{
	_right->run(FORWARD);
	_left->run(BACKWARD);

	for (i = 0; i<PEAK_TURN_SPEED; i++) {
		_right->setSpeed(i);
		_left->setSpeed(i);
		delay(TURN_DELAY);
	}
	for (i = PEAK_TURN_SPEED; i != 0; i--) {
		_right->setSpeed(i);
		_left->setSpeed(i);
		delay(TURN_DELAY);
	}
}

void Car::UeeeLeft()
{
	TurnLeft90();
	TurnLeft90();
}
void Car::UeeeRight()
{
	TurnRight90();
	TurnRight90();
}
void Car::DriveForward(int driveTime)
{
	_right->run(FORWARD);
	_left->run(FORWARD);

	for (i = 0; i<PEAK_DRIVE_SPEED; i++) {
		_right->setSpeed(i);
		_left->setSpeed(i);
		delay(DRIVE_DELAY);
	}

	delay(driveTime);

	for (i = PEAK_DRIVE_SPEED; i != 0; i--) {
		_right->setSpeed(i);
		_left->setSpeed(i);
		delay(DRIVE_DELAY);
	}
}
void Car::DriveBackward(int driveTime)
{
	_right->run(BACKWARD);
	_left->run(BACKWARD);

	for (i = 0; i<PEAK_DRIVE_SPEED; i++) {
		_right->setSpeed(i);
		_left->setSpeed(i);
		delay(DRIVE_DELAY);
	}

	delay(driveTime);

	for (i = PEAK_DRIVE_SPEED; i != 0; i--) {
		_right->setSpeed(i);
		_left->setSpeed(i);
		delay(DRIVE_DELAY);
	}
}
void Car::WideLeft(int driveTime)
{
	_right->run(FORWARD);
	_left->run(FORWARD);

	for (i = 0; i<PEAK_DRIVE_SPEED; i++) {
		_rightSpeed++;
		if (i % 2 == 0)
		{
			_leftSpeed++;
			_left->setSpeed(_leftSpeed);
		}
		_right->setSpeed(_rightSpeed);
		delay(WIDE_TURN_DELAY);
	}

	_left->setSpeed(PEAK_DRIVE_SPEED / 2);
	_right->setSpeed(PEAK_DRIVE_SPEED);

	delay(driveTime);

	for (i = PEAK_DRIVE_SPEED; i != 0; i--) {
		_rightSpeed--;
		_right->setSpeed(_rightSpeed);
		if (i % 2 == 0)
		{
			_leftSpeed--;
			_left->setSpeed(_leftSpeed);
		}
		delay(WIDE_TURN_DELAY);
	}

	_right->setSpeed(0);
	_left->setSpeed(0);
}
void Car::WideRight(int driveTime)
{
	_right->run(FORWARD);
	_left->run(FORWARD);

	for (i = 0; i<PEAK_DRIVE_SPEED; i++) {
		if (i % 2 == 0)
		{
			_rightSpeed++;
			_right->setSpeed(_rightSpeed);
		}
		_leftSpeed++;
		_left->setSpeed(_leftSpeed);
		delay(WIDE_TURN_DELAY);
	}

	_right->setSpeed(PEAK_DRIVE_SPEED / 2);
	_left->setSpeed(PEAK_DRIVE_SPEED);

	delay(driveTime);

	for (i = PEAK_DRIVE_SPEED; i != 0; i--) {
		if (i % 2 == 0)
		{
			_rightSpeed--;
			_right->setSpeed(_rightSpeed);
		}
		_leftSpeed--;
		_left->setSpeed(_leftSpeed);
		delay(WIDE_TURN_DELAY);
	}

	_right->setSpeed(0);
	_left->setSpeed(0);
}

void Car::Wait()
{
	_right->run(RELEASE);
	_left->run(RELEASE);
}

Car::~Car()
{
}
