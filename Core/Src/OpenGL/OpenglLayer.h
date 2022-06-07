#pragma once

#include "../Core/Layer.h"
#include "OpenglBuild.h"

class OpenglLayer : public Layer
{
    public:
        OpenglLayer();
        ~OpenglLayer();

        virtual void onAttach(Window* win) override;
};

