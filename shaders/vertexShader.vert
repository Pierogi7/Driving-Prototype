#version 460
//Triangle position with values retrieved from main.cpp
layout (location = 0) in vec3 position;

//model view project matrix
uniform mat4 mvpIn;

//texture for model
layout (location = 2) in vec2 textureVertex;
out vec2 textureFrag;

//Dynamic lighting
layout (location = 1) in vec3 normalVert;
out vec3 normalVec;
out vec3 fragPos;
uniform mat4 model;

//Triangle vertices sent through gl_Position to next stage
void main()
{
    //Model loading
    gl_Position = mvpIn * vec4(position.x, position.y, position.z, 1.0);
    textureFrag = textureVertex;
    fragPos = vec3(model * vec4(position, 1.0));
    normalVec = normalVert;
}