//GLFW
#include <GLFW/glfw3.h>

#include "camera.h"

//Constructor
Camera::Camera()
{
	//Transformations for camera
	//Relative position within world space
	cameraPosition = vec3(0.0f, 0.0f, 3.0f);
	//The direction of travel
	cameraFront = vec3(0.0f, 0.0f, -1.0f);
	//Up position within world space
	cameraUp = vec3(0.0f, 1.0f, 0.0f);
	//Camera sideways rotation
	cameraYaw = -90.0f;
	//Camera vertical rotation
	cameraPitch = 0.0f;
	//Determines if first entry of mouse into window
	mouseFirstEntry = true;
	//Positions of camera from given last frame
	cameraLastXPos = 800.0f / 2.0f;
	cameraLastYPos = 600.0f / 2.0f;
	//speed
	movementSpeed = BASE_SPEED;
}

//Desctructor
Camera::~Camera()
{
	
}

mat4 Camera::get_view()
{
	//Sets the position of the viewer, the movement direction in relation to it & the world up direction
	return lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
}

//setters
void Camera::set_speed(float timeIn)
{
	movementSpeed = BASE_SPEED * timeIn;
}

//getters
vec3 Camera::get_pos()
{
	return cameraPosition;
}
