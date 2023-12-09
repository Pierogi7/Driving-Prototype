//Shader loader and model loader from learnopepgl tuorials
#include "learnopengl/shader_m.h"
#include "learnopengl/model.h"

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

//Header
#include "Game.h"

//namspace declerations
using namespace glm;
using namespace std;



//Constructor
Game::Game() 
{
	//Initialise GLFW
	glfwInit();
	//Create window
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Drive", NULL, NULL);

	if (window == NULL)
	{
		cout << "GLFW Window did not instantiate\n";
		glfwTerminate();

	}
	//Binding mouse to window and hiding cursor
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	//Binding OpenGL to window
	glfwMakeContextCurrent(window);
	//Initialising GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "GLAD failed to initialise\n";
	}

	//Loading of shaders
	Shader Shaders("shaders/vertexShader.vert", "shaders/fragmentShader.frag");
	Model car("models/car/car.obj");
	Shaders.use();

	//OpenGL viewport set to size of GLFW window
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	//Set our resize func to run on window resize
	//glfwSetFramebufferSizeCallback(window, ResizeViewport);
	//Set our mouse input func to run when the mouse is moved
	//glfwSetCursorPosCallback(window, MouseInput);
}

//Deconstructor
Game::~Game() 
{
	//Cleanup
	glfwTerminate();
}

//Render loop
void Game::Run()
{
	while (glfwWindowShouldClose(window) == false)
	{
		//Input
		KeyboardInput();
		
		//Rendering
		Render();

		//Refreshing
		glfwSwapBuffers(window); //Swaps the colour buffer
		glfwPollEvents(); //Queries all GLFW events
	}
	
}

void Game::Render()
{
	//Rendering
	glClearColor(0.f, 0.f, 0.f, 1.0f); //Colour to display on cleared window
	glClear(GL_COLOR_BUFFER_BIT); //Clears the colour buffer

}

//Resizes viewport to match window size
void Game::ResizeViewport(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

//Take input from keyboard
void Game::KeyboardInput()
{
		// Closes window on 'exit' key press
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}
}