#include "outermeSDL.h"

//

int main(int argc, char* argv[])
{
    int ret = initSDL("SuperTourn", "x.xxx", "Px437_ITT_BIOS_X.ttf", 640, 480, 24);
    SDL_RenderClear(mainRenderer);
    drawText("This is a test for SuperTourn, a new 2D fighting game and successor to calculator game. Thanks.", 0, 0, screenWidth, screenHeight, (SDL_Color) {0, 0, 0}, true);
    waitForKey();
    return ret;
}
