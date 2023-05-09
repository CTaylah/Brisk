#version 450 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

// out vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform mat4 transform;
//uniform mat4 projection_view;

out vec3 Normal;
out vec3 FragPos;

void main()
{
    gl_Position = projection * view * model * transform * vec4(aPos, 1.0);
    FragPos = vec3(model * transform * vec4(aPos, 1.0));
    //TODO: Move to CPU side
    Normal = mat3(transpose(inverse(model))) * aNormal;
    
}