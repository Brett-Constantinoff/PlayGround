#include "PlayGround.h"

PlayGround::PlayGround() : 
Application()
{
    pushLayer(new PlayGroundLayer());
}
