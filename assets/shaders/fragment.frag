#version 450 core
out vec4 FragColor;

in  vec3 FragPos;
in  vec3 Normal;
// in vec2 texCoord;

uniform vec3 objectColor;
uniform vec3 lightColor;

uniform vec3 lightPosition;

void main()
{
    float ambientStrength = 0.1;
    vec3 ambientLight = ambientStrength * lightColor;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPosition - FragPos);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    vec3 result = (ambientLight + diffuse) * objectColor;

    FragColor = vec4(result, 1.0);
}