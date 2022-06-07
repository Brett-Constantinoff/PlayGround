#include "PlayGroundApp.h"

PlayGroundApp::PlayGroundApp() : 
Application()
{
    pushLayer(new PlayGroundLayer());
}
