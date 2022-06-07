#pragma once

#include "Buffer.h"
#include <stdint.h>

class VertexBuffer : public Buffer
{
    public:
        VertexBuffer(uint32_t type);
        virtual ~VertexBuffer();
        
        virtual void bind() override;
        virtual void setData(uint32_t byteSize, void* data, uint32_t mode) override;
        virtual void setSubData(uint32_t offset, int32_t byteSize, void* data) override;

};
