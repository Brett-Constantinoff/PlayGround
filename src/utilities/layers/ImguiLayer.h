#pragma once

#include "../../build/ImguiBuild.h"
#include "../Layer.h"

class ImguiLayer : public Layer
{
    public:
        ImguiLayer();
        virtual ~ImguiLayer();

        void begin();
        void end();

        virtual void onAttach(Window* win) override;
};


