#include <iostream>
#include <string>

#include "glad/glad.h"

#include "stb/stb_image.h"

class Texture
{

public:
    Texture(const std::string filePath);
    void bind();
    void unbind();
    ~Texture();

private:
    unsigned int m_textureID;
    unsigned char *m_TextureData;
    int m_width, m_height, m_nrChannels;

    void setTextureParamters();
    void loadTextureData(const std::string imageFilePath);
};