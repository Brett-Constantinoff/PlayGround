#ifndef PLAYGROUNDLAYER_H
#define PLAYGROUNDLAYER_H

#include "../../Core/Src/Core/Layer.h"
#include "../../Core/Src/OpenGL/OpenglBuild.h"
#include "../../Core/Src/ImGui/ImguiBuild.h"
#include "../../Core/Util/Shader.h"
#include "../../Core/Util/TextRenderer.h"
#include <iostream>
#include <sstream>

class PlayGroundLayer : public Layer{
    public:
        PlayGroundLayer();
        virtual ~PlayGroundLayer();

        virtual void onAttach() override;
        virtual void onDetach() override;
        virtual void onUpdate(float dt, GLFWwindow* win) override;
        virtual void onRender() override; 
        virtual void onRenderImgui() override;

    private:
        Shader* m_shader;
        Shader* m_textShader;
        //TextRenderer* m_textRenderer;
        uint32_t m_vao;
        uint32_t m_vbo;
        uint32_t m_ibo;
        std::stringstream m_frameRate;
};  

#endif