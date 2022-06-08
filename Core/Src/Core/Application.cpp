#include "Application.h"

Application::Application(const std::string& label, uint32_t width, uint32_t height)
{
    m_layerStack = new LayerStack();
    
    m_openglLayer = new OpenglLayer();
    pushLayer(m_openglLayer);

    m_window = new Window(label, width, height);

    m_imguiLayer = new ImguiLayer();
    pushLayer(m_imguiLayer);
}

Application::~Application()
{
    delete m_window;
    delete m_layerStack;
}

void Application::pushLayer(Layer* layer)
{
    m_layerStack->push(layer, m_window);
}

void Application::start()
{
    while(m_window->isOpen())
    {
        float currFrame = glfwGetTime();
        float dt = currFrame - m_lastFrame;
        m_lastFrame = currFrame;

        m_imguiLayer->begin();
        m_layerStack->updateLayers(dt);
        m_imguiLayer->end();

        m_window->update();
    }
}