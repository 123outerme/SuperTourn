#include "outermeSDL.h"
#include "superTourn.h"

int main(int argc, char* argv[])
{
    int ret = initSDL("SuperTourn", "x.xxx", "Px437_ITT_BIOS_X.ttf", 640, 480, 24);
    initConfig("y.yyy");
    SDL_RenderClear(mainRenderer);
    drawText("This is a test for Super-Tourn, a new 2D fighting game and successor to calculator game. Thanks.", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, (SDL_Color) {0, 0, 0}, true);
    waitForKey();
    aMenu(0, "Super-Tourn", "Play", "Options", "Quit", " ", "(Non-functional)", 5, 0, (SDL_Color){0xFF, 0xFF, 0xFF}, (SDL_Color){160, 160, 0}, (SDL_Color){0, 0, 1}, (SDL_Color){0, 0, 0}, true, true);
    return ret;
}
