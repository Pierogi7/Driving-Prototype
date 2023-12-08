//STD for outputting errors to cmd
#include <iostream>

//GLAD to load models and shaders
#include <glad/glad.h>

//GLM for matrix maths
#include "glm/ext/vector_float3.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//GLFW for creating window
#include <GLFW/glfw3.h>

//namspace declerations
using namespace glm;
using namespace std;

//Game class is responsible for game logic
class Game{
public:
	Game();
	~Game();
	//Runs every frame
	void RenderLoop();
	
private:
	//Resizes viewport to match window size
	void ResizeViewport(GLFWwindow* window, int width, int height);
	//Process keyboard input
	void KeyboardInput();
	//Process mouse input
	void MouseInput();

	//Constants
	const int WINDOW_WIDTH = 1600;
	const int WINDOW_HEIGHT = 1200;

	//variables
	GLFWwindow* window;
};