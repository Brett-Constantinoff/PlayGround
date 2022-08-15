#pragma once

#include "Layer.h"
#include "LayerStack.h"
#include "layers/ImguiLayer.h"
#include "layers/OpenglLayer.h"
#include "Window.h"

#include <string.h>

class Application
{
    public:
        Application(const std::string& label = "Application", uint32_t width = 1080, uint32_t height = 720);
        virtual ~Application() = 0;

        void start();
        void pushLayer(Layer* layer);

    private:
        ImguiLayer* m_imguiLayer;
        OpenglLayer* m_openglLayer;
        LayerStack* m_layerStack;
       
        Window* m_window;   

        float m_lastFrame = 0.0f;
};

