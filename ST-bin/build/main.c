#include "outermeSDL.h"
#include "superTourn.h"

int main(int argc, char* argv[])
{
    int ret = initSDL("SuperTourn", "x.xxx", "Px437_ITT_BIOS_X.ttf", 640, 480, 24);
    initConfig("y.yyy");
    SDL_RenderClear(mainRenderer);
    drawText("This is a test for Super-Tourn, a new 2D fighting game and successor to calculator game. Thanks.", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, (SDL_Color) {0, 0, 0}, true);
    waitForKey();
    //aMenu(0, "Super-Tourn", "Play", "Options", "Quit", " ", "(Non-functional)", 5, 0, (SDL_Color){0xFF, 0xFF, 0xFF}, (SDL_Color){160, 160, 0}, (SDL_Color){0, 0, 1}, (SDL_Color){0, 0, 0}, true, true);
    int gameState = 0;
    bool quit = false;
    while(!quit)
    switch(gameState)
    {
    case 0:
        mainLoop();
        gameState = 1;
        break;
    case 1:
        quit = true;
        break;
    }
    return ret;
}

void mainLoop()
{
    SDL_Event e;
    bool quit = false;
    fighter character;
    {
        hurtbox boxes[3];
        sprite sprites[3];
        SDL_Rect rects[3] = {(SDL_Rect) {0, 0, 32, 32}, (SDL_Rect) {-1, 32, 34, 32}, (SDL_Rect) {-2, 64, 36, 32}};
        for(int i = 0; i < 3; i++)
        {
            initHurtbox(&boxes[i], rects[i], normal);
            initSprite(&sprites[i], rects[i].x, rects[i].y, rects[i].w, 0, type_na);
        }
        initFighter(&character, boxes, (SDL_Rect) {10, 90, 36, 96}, 12, sprites, 1, 1);
    }
    SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    while(!quit)
    {
        SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(mainRenderer);
        SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 0xFF);
        for(int i = 0; i < 3; i++)
            SDL_RenderDrawRect(mainRenderer, &((SDL_Rect) {.x =  character.rect.x + character.boxes[i].rect.x, .y = character.rect.y + character.boxes[i].rect.y, .w = character.boxes[i].rect.w, .h = character.boxes[i].rect.h}));
        while(SDL_PollEvent(&e) != 0)  //while there are events in the queue
            if (e.type == SDL_QUIT)
                quit = true;
        const Uint8* keyStates = SDL_GetKeyboardState(NULL);
        if (keyStates[SDL_SCANCODE_ESCAPE])
            quit = true;
        character.rect.x += (keyStates[SDL_SCANCODE_D] && character.rect.x < SCREEN_WIDTH - character.rect.w) - (keyStates[SDL_SCANCODE_A] && character.rect.x > 0);
        SDL_RenderPresent(mainRenderer);
    }
}
