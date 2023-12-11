//GLM
#include "glm/ext/vector_float3.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

class Camera
{
public:
	Camera();
	~Camera();

	//getters
	mat4 get_view();
	vec3 get_pos();

	//setters
	void set_speed(float timeIn);

	//var
	vec3 cameraPosition;
	vec3 cameraFront;
	vec3 cameraUp;
	float cameraYaw;
	float cameraPitch;
	float cameraLastXPos;
	float cameraLastYPos;
	float movementSpeed;
	bool mouseFirstEntry;

private:
	//const
	const float BASE_SPEED = 3.f;
};

