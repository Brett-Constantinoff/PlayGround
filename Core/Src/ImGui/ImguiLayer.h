#pragma once

#include "ImguiBuild.h"
#include "../Core/Layer.h"

class ImguiLayer : public Layer
{
    public:
        ImguiLayer();
        virtual ~ImguiLayer();

        void begin();
        void end();

        virtual void onAttach(Window* win) override;
};


