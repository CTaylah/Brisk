#version 450 core
out vec4 FragColor;
// in vec2 texCoord;

// uniform vec4 color;
// uniform sampler2D ourTexture;

void main()
{
    
    // FragColor = texture(ourTexture, texCoord);
    // FragColor.z = color.x; 

    FragColor = vec4(0.8f, 0.8f, 0.5f, 1.0f);
}