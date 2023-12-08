//Header
#include "Game.h"

//Constructor
Game::Game() 
{
	//Initialise GLFW
	glfwInit();
	//Create window
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Drive", NULL, NULL);
	//Binding mouse to window and hiding cursor
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	//Binding OpenGL to window
	glfwMakeContextCurrent(window);
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
	glfwTerminate();
}

//Render loop
void Game::RenderLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		//Input
		KeyboardInput();
		
		//Rendering
		glClearColor(0.f, 0.f, 0.f, 1.0f); //Colour to display on cleared window
		glClear(GL_COLOR_BUFFER_BIT); //Clears the colour buffer
		

		//Refreshing
		glfwSwapBuffers(window); //Swaps the colour buffer
		glfwPollEvents(); //Queries all GLFW events
	}
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