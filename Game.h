#include <GLFW/glfw3.h>

//Game class is responsible for game logic
class Game{
public:
	Game();
	~Game();
	//Runs every frame
	void Run();
	
private:
	//Called in render loop
	void Render();
	//Called in render loop
	void Refresh();
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