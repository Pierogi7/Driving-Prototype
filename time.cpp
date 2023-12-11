#include <GLFW/glfw3.h>

#include "time.h"

//constructor
Time::Time()
{
	deltaTime = 0.f;
	lastFrame = 0.f;
}

//destructor
Time::~Time()
{
}

//called in render loop
void Time::Calc()
{
	//grab time from GLFW
	float currentFrame = static_cast<float>(glfwGetTime());
	//time passed since last frame
	deltaTime = currentFrame - lastFrame;
	//set last frame for next call
	lastFrame = currentFrame;
}

float Time::get_delta()
{
	return deltaTime;
}