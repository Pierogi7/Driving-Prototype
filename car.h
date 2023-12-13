//GLM
#include "glm/ext/vector_float3.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

// A class for controlling the car
class Car
{
public:
	Car();
	~Car();

	void AdjustSpeed(char keyIn, float timeIn);

	//movement for car
	mat4 accelerate(float timeIn);
	mat4 Decelerate(float timeIn);
	mat4 turn_left(float timeIn);
	mat4 turn_right(float timeIn);

	float currentSpeed;
	mat4 transform;

private:
	//consts
	const float BASE_SPEED = 3.f;
	const float MAX_SPEED = 30.f;
};

