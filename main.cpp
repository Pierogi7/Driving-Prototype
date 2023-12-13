//STD
#include <iostream>

//GLAD
#include <glad/glad.h>

//LEARNOPENGL
#include <learnopengl/shader_m.h>
#include <learnopengl/model.h>

//GLM
#include "glm/ext/vector_float3.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//header files
#include "main.h"
#include "camera.h"
#include "time.h"
#include "mvp.h"


using namespace glm;
using namespace std;

const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 1200;

Camera gameCam;
Time gameTime;
MVP gameMvp(WINDOW_WIDTH, WINDOW_HEIGHT);

int main()
{

    //Initialisation of GLFW
    glfwInit();

    //Initialisation of 'GLFWwindow' object
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Drive", NULL, NULL);

    //Checks if window has been successfully instantiated
    if (window == NULL)
    {
        cout << "GLFW Window did not instantiate\n";
        glfwTerminate();
        return -1;
    }

    //Sets cursor to automatically bind to window & hides cursor pointer
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    //Binds OpenGL to window
    glfwMakeContextCurrent(window);

    //Initialisation of GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "GLAD failed to initialise\n";
        return -1;
    }

    //Loading of shaders
    Shader shaders("shaders/vertexShader.vert", "shaders/fragmentShader.frag");
    Model car("models/car/car.obj");
    shaders.use();

    //Sets the viewport size within the window to match the window size of WINDOW_WIDTHxWINDOW_HEIGHT
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    //Sets the framebuffer_size_callback() function as the callback for the window resizing event
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //Sets the mouse_callback() function as the callback for the mouse movement event
    //glfwSetCursorPosCallback(window, mouse_callback);

    //Dynamic lighting
    shaders.setMat4("model", gameMvp.model);
    shaders.setVec3("lightPos", vec3(0.f, 5.f, -10.f));

    RenderLoop(window, shaders, car);

    //Safely terminates GLFW
    glfwTerminate();

    return 0;
}
void RenderLoop(GLFWwindow* windowIn, Shader& shadersIn, Model& carIn)
{
    //Render loop
    while (glfwWindowShouldClose(windowIn) == false)
    {
        //Time
        gameTime.Calc(); //Calculates delta time
        gameCam.set_speed(gameTime.get_delta());

        //Input
        ProcessUserInput(windowIn); //Takes user input

        //Rendering
        Render();

        //Drawing
        Draw(shadersIn, carIn);

        //Shading
        UpdateShaders(shadersIn);

        //Refreshing
        Refresh(windowIn);
    }
}

void UpdateShaders(Shader& shadersIn)
{
    //specular Lighting, need camera pos
    shadersIn.setVec3("viewPos", gameCam.get_pos());
}

void Draw(Shader& shadersIn, Model& carIn)
{
    gameMvp.view = gameCam.get_view();

    SetMatrices(shadersIn);
    carIn.Draw(shadersIn);
}

void Render()
{
    glClearColor(0.25f, 0.0f, 1.0f, 1.0f); //Colour to display on cleared window
    glClear(GL_COLOR_BUFFER_BIT); //Clears the colour buffer
    glEnable(GL_CULL_FACE); //Discards all back-facing triangles
}

void Refresh(GLFWwindow* windowIn)
{
    glfwSwapBuffers(windowIn); //Swaps the colour buffer
    glfwPollEvents(); //Queries all GLFW events
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //Resizes window based on contemporary width & height values
    glViewport(0, 0, width, height);
}

void ProcessUserInput(GLFWwindow* windowIn)
{
    //Closes window on 'exit' key press
	if (glfwGetKey(windowIn, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(windowIn, true);
	}

    //"Camera movement"
    //frame independent input
    
    //User input for camera
    //WASD
    if (glfwGetKey(windowIn, GLFW_KEY_W) == GLFW_PRESS)
    {
        gameCam.MoveForward();
    }
    if (glfwGetKey(windowIn, GLFW_KEY_S) == GLFW_PRESS)
    {
        gameCam.MoveBack();
    }
    if (glfwGetKey(windowIn, GLFW_KEY_A) == GLFW_PRESS)
    {
        gameCam.MoveLeft();
    }
    if (glfwGetKey(windowIn, GLFW_KEY_D) == GLFW_PRESS)
    {
        gameCam.MoveRight();
    }
    //moving up and down
    if (glfwGetKey(windowIn, GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        gameCam.MoveUp();
    }
    if (glfwGetKey(windowIn, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
    {
        gameCam.MoveDown();
    }

}
//legacy mouse handling
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//    //Initially no last positions, so sets last positions to current positions
//    if (mouseFirstEntry)
//    {
//        cameraLastXPos = (float)xpos;
//        cameraLastYPos = (float)ypos;
//        mouseFirstEntry = false;
//    }
//
//    //Sets values for change in position since last frame to current frame
//    float xOffset = (float)xpos - cameraLastXPos;
//    float yOffset = cameraLastYPos - (float)ypos;
//
//    //Sets last positions to current positions for next frame
//    cameraLastXPos = (float)xpos;
//    cameraLastYPos = (float)ypos;
//
//    //Moderates the change in position based on sensitivity value
//    const float sensitivity = 0.025f;
//    xOffset *= sensitivity;
//    yOffset *= sensitivity;
//
//    //Adjusts yaw & pitch values against changes in positions
//    cameraYaw += xOffset;
//    cameraPitch += yOffset;
//
//    //Prevents turning up & down beyond 90 degrees to look backwards
//    if (cameraPitch > 89.0f)
//    {
//        cameraPitch = 89.0f;
//    }
//    else if (cameraPitch < -89.0f)
//    {
//        cameraPitch = -89.0f;
//    }
//
//    //Modification of direction vector based on mouse turning
//    vec3 direction;
//    direction.x = cos(radians(cameraYaw)) * cos(radians(cameraPitch));
//    direction.y = sin(radians(cameraPitch));
//    direction.z = sin(radians(cameraYaw)) * cos(radians(cameraPitch));
//    cam.cameraFront = normalize(direction);
//
//}

void SetMatrices(Shader& shadersIn)
{
    gameMvp.mvpMatrix = gameMvp.projection * gameMvp.view * gameMvp.model; //Setting of MVP
    shadersIn.setMat4("mvpIn", gameMvp.mvpMatrix); //Setting of uniform with Shader clas\s
}