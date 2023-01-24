#version 450 core
out vec4 FragColor;
in vec2 texCoord;

uniform vec4 color;
uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture, texCoord);
    FragColor.z = color.x; 
}