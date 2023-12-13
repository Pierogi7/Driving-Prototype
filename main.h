#pragma once

//framebuffer_size_callback() needs GlFW, so include moved here
#include <GLFW/glfw3.h>

//Called on window resize
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//Processes user input on a particular window
void ProcessUserInput(GLFWwindow* WindowIn, Shader& shadersIn, float timeIn);
//Called on mouse movement
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//Sets the model-view-projection matrix
void SetMatrices(Shader& ShaderProgramIn);

//Called in render loop
void Draw(Shader& shadersIn, Model& carIn, float timeIn);
void Render();
void Refresh(GLFWwindow* windowIn);
void UpdateShaders(Shader& shadersIn);

//Render loop
void RenderLoop(GLFWwindow* windowIn, Shader& shadersIn, Model& carIn);
