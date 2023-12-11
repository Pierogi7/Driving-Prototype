#include "mvp.h"

//Constructor
MVP::MVP(int width, int height)
{
    //Setting default values
    //Model matrix
    model = mat4(1.0f);
    //Scaling to zoom in
    model = scale(model, vec3(0.025f, 0.025f, 0.025f));
    //Rotation to look down
    model = rotate(model, radians(0.0f), vec3(1.0f, 0.0f, 0.0f));
    //Movement to position further back
    model = translate(model, vec3(0.0f, -2.f, -1.5f));
    //View matrix
    view = lookAt(vec3(0.0f, 0.0f, 3.0f), vec3(0.0f, 0.0f, 2.0f), vec3(0.0f, 1.0f, 0.0f));
    //Projection matrix
    projection = perspective(radians(45.0f), (float)width / (float)height, 0.f, 100.0f);
    //Model-view-projection matrix uniform for vertex shader
    mvpMatrix = projection * view * model;
}

//Destructor
MVP::~MVP()
{
}