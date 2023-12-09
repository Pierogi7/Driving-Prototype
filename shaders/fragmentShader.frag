#version 460
//Colour value to send to next stage
out vec4 FragColor;

//model loading textures
in vec2 textureFrag;
uniform sampler2D texture_diffuse1;

//Dynamic lighting
in vec3 normalVec;
uniform vec3 lightPos;
in vec3 fragPos;

//Specular highlights
uniform vec3 viewPos;

void main()
{
    //ambient light calc
    float ambientStrength = 0.1;
    vec3 lightColour = new vec3(1, 1, 1);
    vec3 ambient = ambientStrength * lightColour;

    //dynamic light calc
    vec3 norm = normalize(normalVec);
    vec3 lightDir = normalize(lightPos - fragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColour;

    //Specular light calc
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColour;  

    //Final light matrix
    vec3 lightResult = (ambient + diffuse + specular);

    //model loading textures with glad and light applied
    FragColor = vec4(lightResult, 1.0f) * texture(texture_diffuse1, textureFrag);

}