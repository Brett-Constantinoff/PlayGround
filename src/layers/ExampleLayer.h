#pragma once

#include "../utilities/Layer.h"
#include "../utilities/Application.h"
#include "../build/OpenglBuild.h"
#include "../build/ImguiBuild.h"
#include "../utilities/VertexBuffer.h"
#include "../utilities/VertexArray.h"
#include "../utilities/Shader.h"
#include "../utilities/TextRenderer.h"
#include "../utilities/Camera.h"
#include "../libs/glm/glm.hpp"
#include "../libs/glm/gtc/matrix_transform.hpp"
#include "../libs/glm/gtc/type_ptr.hpp"

#include <iostream>
#include <sstream>

class ExampleLayer : public Layer
{
    public:
        ExampleLayer();
        virtual ~ExampleLayer();

        virtual void onAttach(Window* win) override;
        virtual void onDetach() override;
        virtual void onUpdate(float dt) override;
        virtual void onRender() override; 
        virtual void onRenderImgui() override;

    private:
        Window* m_window;
        Shader* m_shader;
        Shader* m_textShader;
        Camera* m_camera;
        TextRenderer* m_textRenderer;
        VertexArray* m_vao;
        std::stringstream m_frameRate;

        glm::mat4 m_projection;
        glm::mat4 m_view;

        glm::vec3 m_quadColour;
};  
