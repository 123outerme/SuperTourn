#include "outermeSDL.h"

//Px437_ITT_BIOS_X.ttf

int main(int argc, char* argv[])
{
    int ret;
    printf("%d\n", ret = initSDL("SuperTourn", "x.xxx", "y.yyy", 640, 480, 24));
    waitForKey();
    printf("This is a test for SuperTourn, a new 2D fighting game and successor to calculator game. Thanks.");
    return 0;
}
