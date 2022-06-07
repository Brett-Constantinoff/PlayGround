#pragma once

#include "Buffer.h"
#include "../Libs/Stb/stb_image.h"
#include <stdint.h>
#include <iostream>

class TextureBuffer : public Buffer
{
    public:
        TextureBuffer(uint32_t type);
        virtual ~TextureBuffer();
        
        virtual void bind();

        void loadTextureData(const char* fileName);
        void setParameter(uint32_t name, uint32_t param);

};
