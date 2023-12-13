#include "car.h"

//constructor
Car::Car()
{
	currentSpeed = 0.f;
}

//desctructor
Car::~Car()
{
}

//Adjust the speed of the car based on user input
//Slows the car to a stop when no input is being given to simulate momentum
void Car::AdjustSpeed(char keyIn, float timeIn)
{
	switch (keyIn)
	{
	case 'w':
		//ternary op prevents accellerating beyond max speed
		currentSpeed = (currentSpeed <= MAX_SPEED) ? currentSpeed + (BASE_SPEED * timeIn) : MAX_SPEED;
		break;
	case 's':
		//same for reversing
		currentSpeed = (currentSpeed >= -MAX_SPEED) ? currentSpeed - (BASE_SPEED * timeIn) : -MAX_SPEED;
		break;
	default:
		//car comes to a stop automatically without input
		if (currentSpeed >0)
		{
			//loss of momentum when going forwards
			currentSpeed -= (BASE_SPEED * timeIn);
		}
		else if (currentSpeed <0)
		{
			//loss of momentum when going backwards
			currentSpeed += (BASE_SPEED * timeIn);
		}
		break;
	}
}

//movement implementation
mat4 Car::accelerate(float timeIn)
{
	//adjust speed by delta time
	

	//matrix maths
	transform = mat4(1.0f);
	transform = translate(transform, vec3(0.f, 0.f, -currentSpeed));

	return transform;
}
mat4 Car::Decelerate(float timeIn)
{
	

	//matrix maths
	transform = mat4(1.0f);
	transform = translate(transform, vec3(0.f, 0.f, currentSpeed));

	return transform;
}
//Rotating car based on speed to imitate turning
mat4 Car::turn_left(float timeIn)
{
	currentSpeed = BASE_SPEED * timeIn;

	transform = mat4(1.f);
	transform = rotate(transform, timeIn, vec3(0.f, currentSpeed ,0.f));

	return transform;
}
mat4 Car::turn_right(float timeIn)
{
	currentSpeed = BASE_SPEED * timeIn;

	transform = mat4(1.f);
	transform = rotate(transform, timeIn, vec3(0.f, -currentSpeed, 0.f));

	return transform;
}