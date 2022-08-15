#include "utilities/Application.h"
#include "utilities/TextRenderer.h"
#include "layers/ExampleLayer.h"

class PlayGround : public Application
{
    public:
        PlayGround(const std::string label) : Application(label)
        {
            pushLayer(new ExampleLayer());
        }
};

int main()
{
    PlayGround* engine = new PlayGround("PlayGround Engine");
    engine->start();
    delete engine;
    return 0;
}