#pragma once

#include "../../Core/Src/Core/Layer.h"
#include "../../Core/Src/Core/Application.h"
#include "../../Core/Src/OpenGL/OpenglBuild.h"
#include "../../Core/Src/ImGui/ImguiBuild.h"
#include "../../Core/Util/VertexBuffer.h"
#include "../../Core/Util/VertexArray.h"
#include "../../Core/Util/Shader.h"
#include "../../Core/Util/TextRenderer.h"
#include "../../Core/Util/Camera.h"
#include "../../Core/Libs/glm/glm.hpp"
#include "../../Core/Libs/glm/gtc/matrix_transform.hpp"
#include "../../Core/Libs/glm/gtc/type_ptr.hpp"
#include <iostream>
#include <sstream>

class PlayGroundLayer : public Layer
{
    public:
        PlayGroundLayer();
        virtual ~PlayGroundLayer();

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
