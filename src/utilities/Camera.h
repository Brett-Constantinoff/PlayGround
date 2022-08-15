#pragma once

#include "../libs/glm/glm.hpp"
#include "../libs/glm/gtc/matrix_transform.hpp"
#include "../libs/glm/gtc/type_ptr.hpp"
#include "../build/OpenglBuild.h"

class Camera
{
    public:
        Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up);
        void move(GLFWwindow **win, float dt);
        glm::mat4* getView( void );

    private:
        glm::mat4 m_view;
        glm::vec3 m_position;
        glm::vec3 m_front;
        glm::vec3 m_up;
        float m_yaw = -90.0f;
        float m_pitch = 0.0f;
};

