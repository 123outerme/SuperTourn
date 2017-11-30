#include "outermeSDL.h"

typedef enum {
    none,  //0
    grab,  //1
    noPriority,  //2  -- only causes knockback on a sensitive hurtbox, has lowest priority
    lowPriority,  //3  -- only causes knockback on sensitive/normal hurtboxes, only beats noPriority
    midPriority,  //4  -- only causes knockback on sensitive/normal hurtboxes, only loses to highPriority
    highPriority,  //5 -- causes knockback on all hurtboxes, doesn't lose
} hitboxType;

typedef enum {
    na,  //0
    sensititve,  //1  -- increased state of damage/knockback gain and amount of hitboxes that can do knockback
    normal,  //2  -- normal state of damage/knockback gain
    superArmor,  //3  -- decreased state of knockback gain, same damage gain. Can't be knocked back by lowPriority attacks
    hyperArmor,  //4  -- decreased state of both knockgack and damage gain. Can't be knocked back by midPriority attacks
    invincible  //5  -- nothing can do damage or knockback except direct modifiactions to the values
} hurtboxType;

typedef struct {
    int x;
    int y;
    int w;
    int h;
    int onFrame;
    int frameOut;
    int activeLength;
    hitboxType hitType;

} hitbox;

typedef struct {
    int relX;
    int relY;
    int w;
    int h;
    hurtboxType hurtType;
} hurtbox;

typedef struct {
    hurtbox* boxes;  //hit/hurtboxes for the given model
} model;

typedef struct {
    hitbox* boxes;
    int frameLength;
    int damage;
    int knockback;
} attack;
