#pragma once

#include "../Core/Layer.h"
#include "ImguiBuild.h"


class ImguiLayer : public Layer
{
    public:
        ImguiLayer();
        virtual ~ImguiLayer();

        void begin();
        void end();

        virtual void onAttach(Window* win) override;
};


