#include "PlayGroundApp.h"

int main(){
    PlayGroundApp* playGroundApp = new PlayGroundApp();
    playGroundApp->start();
    delete playGroundApp;
    return 0;
}