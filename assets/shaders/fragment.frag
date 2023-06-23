#version 450 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec3 CameraPos;
// in vec2 texCoord;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPosition;
uniform vec3 cameraPosition;
uniform float shininess;

void main()
{
    //ambient
    float ambientStrength = 0.1;
    vec3 ambientLight = ambientStrength * lightColor;

    //diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPosition - FragPos);
    float intensity = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = intensity * lightColor;


    //specular
    float specularStrength = 0.5;

    vec3 viewDir = normalize(cameraPosition - FragPos);
    vec3 refDir = reflect(-lightDir, norm);
    float angle = max(dot(viewDir,refDir), 0.0);
    float spec = pow(angle, shininess);
    vec3 specular = specularStrength * spec * lightColor ;

    vec3 result = (ambientLight + diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.0);
}