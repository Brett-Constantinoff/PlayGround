#ifndef OPENGLLAYER_H
#define OPENGLLAYER_H

#define GL_SILENCE_DEPRECATION

#include "../Core/Layer.h"
#include <iostream>

#include "OpenglBuild.h"


class OpenglLayer : public Layer{
    public:
        OpenglLayer();
        ~OpenglLayer();

        virtual void onAttach() override;
};

#endif