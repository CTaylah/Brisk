#include "Texture.h"

namespace Brisk {
    Texture::Texture(const std::string imageFilePath)
    {
        glGenTextures(1, &m_textureID);
        glActiveTexture(GL_TEXTURE0);
        bind();
        setTextureParamters();
        loadTextureData(imageFilePath);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_TextureData);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(m_TextureData);
    }

    void Texture::bind()
    {
        glBindTexture(GL_TEXTURE_2D, m_textureID);
    }

    void Texture::unbind()
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    Texture::~Texture()
    {
        glDeleteTextures(1, &m_textureID);
    }

    void Texture::loadTextureData(const std::string imageFilePath)
    {
        m_TextureData = stbi_load(imageFilePath.c_str(), &m_width, &m_height, &m_nrChannels, 0);
        if (!m_TextureData)
            std::cout << "stb_image error. Unable to load texture image from: " + imageFilePath << std::endl;
    }

    void Texture::setTextureParamters()
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
}