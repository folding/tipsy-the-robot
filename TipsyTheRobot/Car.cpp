#include "Car.h"


#define PEAK_DRIVE_SPEED 255
#define DRIVE_DELAY 8


Adafruit_DCMotor *_leftMotor;
Adafruit_DCMotor *_rightMotor;
uint8_t i;
uint8_t _leftSpeed = 0;
uint8_t _rightSpeed = 0;

uint8_t _rightTargetSpeed = 0;
uint8_t _leftTargetSpeed = 0;

uint8_t _leftDirection = FORWARD;
uint8_t _rightDirection = FORWARD;

uint8_t _leftTargetDirection = FORWARD;
uint8_t _rightTargetDirection = FORWARD;

Car::Car(Adafruit_DCMotor *left, Adafruit_DCMotor *right)
{
	_leftMotor = left;
	_rightMotor = right;
}

void Car::Start()
{
	// Set the speed to start, from 0 (off) to 255 (max speed)
	_leftMotor->setSpeed(_leftSpeed);
	_leftMotor->run(FORWARD);
	// turn on motor
	_leftMotor->run(RELEASE);

	// Set the speed to start, from 0 (off) to 255 (max speed)
	_rightMotor->setSpeed(_rightSpeed);
	_rightMotor->run(FORWARD);
	// turn on motor
	_rightMotor->run(RELEASE);
}

void Car::UeeeLeft()
{
	_leftTargetDirection = BACKWARD;
	_rightTargetDirection = FORWARD;
	_rightTargetSpeed = PEAK_DRIVE_SPEED;
	_leftTargetSpeed = PEAK_DRIVE_SPEED;
}
void Car::UeeeRight()
{
	_leftTargetDirection = FORWARD;
	_rightTargetDirection = BACKWARD;
	_rightTargetSpeed = PEAK_DRIVE_SPEED;
	_leftTargetSpeed = PEAK_DRIVE_SPEED;
}
void Car::DriveForward()
{
	_leftTargetDirection = FORWARD;
	_rightTargetDirection = FORWARD;
	_rightTargetSpeed = PEAK_DRIVE_SPEED;
	_leftTargetSpeed = PEAK_DRIVE_SPEED;
}
void Car::DriveBackward()
{
	_leftTargetDirection = BACKWARD;
	_rightTargetDirection = BACKWARD;
	_rightTargetSpeed = PEAK_DRIVE_SPEED;
	_leftTargetSpeed = PEAK_DRIVE_SPEED;
}
void Car::WideLeft()
{
	_leftTargetDirection = FORWARD;
	_rightTargetDirection = FORWARD;
	_rightTargetSpeed = PEAK_DRIVE_SPEED;
	_leftTargetSpeed = PEAK_DRIVE_SPEED / 2;
}
void Car::WideRight()
{
	_leftTargetDirection = FORWARD;
	_rightTargetDirection = FORWARD;
	_rightTargetSpeed = PEAK_DRIVE_SPEED / 2;
	_leftTargetSpeed = PEAK_DRIVE_SPEED;
}

void Car::Stop()
{
	_leftTargetDirection = FORWARD;
	_rightTargetDirection = FORWARD;
	_rightTargetSpeed = 0;
	_leftTargetSpeed = 0;
}

void Car::Run()
{
	//check targets, if running the opposite direction slow it down
	if (_leftDirection != _leftTargetDirection)
	{
		if (_leftSpeed > 0)
		{
			_leftSpeed--;
		}

		if (_leftSpeed == 0)
		{
			_leftDirection = _leftTargetDirection;
		}
	}
	else if (_leftSpeed < _leftTargetSpeed)
	{
		_leftSpeed++;
	}
	else if (_leftSpeed > _leftTargetSpeed)
	{
		_leftSpeed--;
	}

	if (_rightTargetDirection != _rightDirection)
	{
		if (_rightSpeed > 0)
		{
			_rightSpeed--;
		}

		if (_rightSpeed == 0)
		{
			_rightDirection = _rightTargetDirection;
		}
	}
	else if (_rightSpeed < _rightTargetSpeed)
	{
		_rightSpeed++;
	}
	else if (_rightSpeed > _rightTargetSpeed)
	{
		_rightSpeed--;
	}

	//accelerate
	_leftMotor->run(_leftDirection);
	_rightMotor->run(_rightDirection);
	_leftMotor->setSpeed(_leftSpeed);
	_rightMotor->setSpeed(_rightSpeed);

	delay(DRIVE_DELAY);
}

bool Car::Accelerating()
{
	return !(_leftSpeed == _leftTargetSpeed &&
			_rightSpeed == _rightTargetSpeed &&
			_leftDirection == _leftTargetDirection &&
			_rightDirection == _rightTargetDirection);
}

void Car::Wait()
{
	_rightMotor->run(RELEASE);
	_leftMotor->run(RELEASE);
}

Car::~Car()
{
}
