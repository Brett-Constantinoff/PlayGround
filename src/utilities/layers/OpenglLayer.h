#pragma once

#include "../Layer.h"
#include "../../build/OpenglBuild.h"

class OpenglLayer : public Layer
{
    public:
        OpenglLayer();
        ~OpenglLayer();

        virtual void onAttach(Window* win) override;
};

