#pragma once

#include <stdint.h>

#include "../build/OpenglBuild.h"

class VertexArray
{
    public:
        VertexArray();
        ~VertexArray();

        void bind();
        void unBind();

        void setAttribPointer(uint32_t location, uint32_t byteSize, uint32_t type, bool normalized, uint32_t stride, void* start, bool instanced = false);

    private:
        uint32_t m_id;
};
