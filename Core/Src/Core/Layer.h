#ifndef LAYER_H
#define LAYER_H

#include <string>
#include "../OpenGL/OpenglBuild.h"

class Layer{
    public: 
        Layer(const std::string& name = "Layer");
        virtual ~Layer() = default;

        virtual void onAttach() {};
        virtual void onDetach() {};
        virtual void onUpdate(float dt, GLFWwindow* win) {};
        virtual void onRender() {};
        virtual void onRenderImgui() {};

    protected:
        std::string m_name;
        GLFWwindow* m_winID;

};

#endif