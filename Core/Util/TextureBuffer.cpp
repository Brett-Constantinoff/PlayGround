#include "TextureBuffer.h"

TextureBuffer::TextureBuffer(uint32_t type) : 
Buffer(type)
{
    glGenTextures(1, &m_id);
}

TextureBuffer::~TextureBuffer()
{
    glDeleteTextures(1, &m_id);
}

void TextureBuffer::bind()
{
    glBindTexture(m_type, m_id);
}

void TextureBuffer::loadTextureData(const char* filename)
{
    int width;
    int height;
    int numChannels;
    uint8_t* data = stbi_load(filename, &width, &height, &numChannels, 0);
    if(data)
    {
        glTexImage2D(m_type, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(m_type);
    }
    else
    {
         std::cout << "Failed to load texture " << filename <<  std::endl;
    }
    stbi_image_free(data);
}

void TextureBuffer::setParameter(uint32_t name, uint32_t param)
{
    glTexParameteri(m_type, name, param);
}
