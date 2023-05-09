#version 450 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec3 CameraPos;
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

    float intensity = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = intensity * lightColor;


    float specularStrength = 0.5;

    float shininess = 16;
    vec3 viewDir = normalize(-FragPos);
    vec3 refDir = reflect(-lightDir, norm);
    float angle = max(dot(viewDir,refDir), 0.0);


    float spec = pow(angle, shininess);
    vec3 specular = spec * specularStrength * lightColor ;
    vec3 result = (ambientLight + diffuse + specular) * objectColor;

    FragColor = vec4(result, 1.0);
}