#include "outermeSDL.h"

typedef enum {
    none,  //0
    grab,  //1
    lowPriority,  //2
    midPriority,  //3
    highPriority,  //4
} hitboxType;

typedef enum {
    sensititve,  //0
    normal,  //1
    superArmor,  //2
    hyperArmor,  //3
    invincible  //4
} hurtboxType;

typedef struct {
    int x;
    int y;
    int w;
    int h;
    hitboxType type;
} hitbox;
