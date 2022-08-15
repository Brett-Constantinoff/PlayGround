#pragma once

#include "../build/OpenglBuild.h"
#include "../build/ImguiBuild.h"
#include "../libs/glm/glm.hpp"
#include "../libs/glm/gtc/matrix_transform.hpp"
#include "../libs/glm/gtc/type_ptr.hpp"
#include "Window.h"

class MousePicker
{
    public:
        MousePicker(float clickSpeed);
        ~MousePicker();

        void getMouseRay(Window* win, glm::mat4 projection, glm::mat4 view);
        bool rayIntersectCube(glm::mat4 transform, glm::vec3 min, glm::vec3 max);
        float getClickSpeed();

    private:
        bool perpPlaneIntersect(glm::vec3 axis, glm::vec3 delta, glm::vec3 rayDir, glm::vec3 min, glm::vec3 max, float& tMin, float& tMax);

    private:
        glm::vec3 m_rayDir;
	    glm::vec3 m_rayOrigin;
        float m_clickSpeed;
};
