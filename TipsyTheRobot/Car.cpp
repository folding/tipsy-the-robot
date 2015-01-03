#include "Car.h"

#define PEAK_TURN_SPEED 240
#define TURN_DELAY 5

#define PEAK_DRIVE_SPEED 255
#define DRIVE_DELAY 8

Adafruit_DCMotor *_left;
Adafruit_DCMotor *_right;
uint8_t i;


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
void Car::DriveForward()
{
	_right->run(FORWARD);
	_left->run(FORWARD);

	for (i = 0; i<PEAK_DRIVE_SPEED; i++) {
		_right->setSpeed(i);
		_left->setSpeed(i);
		delay(DRIVE_DELAY);
	}
	for (i = PEAK_TURN_SPEED; i != 0; i--) {
		_right->setSpeed(i);
		_left->setSpeed(i);
		delay(DRIVE_DELAY);
	}
}
void Car::DriveBackward()
{
	_right->run(BACKWARD);
	_left->run(BACKWARD);

	for (i = 0; i<PEAK_DRIVE_SPEED; i++) {
		_right->setSpeed(i);
		_left->setSpeed(i);
		delay(DRIVE_DELAY);
	}
	for (i = PEAK_TURN_SPEED; i != 0; i--) {
		_right->setSpeed(i);
		_left->setSpeed(i);
		delay(DRIVE_DELAY);
	}
}

void Car::Wait()
{
	_right->run(RELEASE);
	_left->run(RELEASE);
}

Car::~Car()
{
}
