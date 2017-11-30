#include "outermeSDL.h"

typedef enum {
    none,  //0
    grab,  //1  -- upon landing on a non-invincible hitbox, starts a grab
    noPriority,  //2  -- only causes knockback on a sensitive hurtbox, has lowest priority
    lowPriority,  //3  -- only causes knockback on sensitive/normal hurtboxes, only beats noPriority
    midPriority,  //4  -- only causes knockback on sensitive/normal hurtboxes, only loses to highPriority
    highPriority,  //5 -- causes knockback on all hurtboxes, doesn't lose
} hitboxType;

typedef enum {
    na,  //0  -- no hurtbox at all
    sensititve,  //1  -- increased state of damage/knockback gain and amount of hitboxes that can do knockback
    normal,  //2  -- normal state of damage/knockback gain
    superArmor,  //3  -- decreased state of knockback gain, same damage gain. Can't be knocked back by lowPriority attacks
    hyperArmor,  //4  -- decreased state of both knockgack and damage gain. Can't be knocked back by midPriority attacks
    invincible  //5  -- nothing can do damage or knockback except direct modifications to the values, no grabs; attack stopped
} hurtboxType;

typedef struct {
    int relX;
    int relY;
    int w;
    int h;
    int onFrame;  //the current frame the hitbox is on
    int frameOut;  //the frame the attack starts to be active
    int activeLength;  //the length, in frames, of the active status
    hitboxType hitType;

} hitbox;

typedef struct {
    int relX;  //x-coord relative to left x of character
    int relY;  //y-coord relative to top y of character
    int w;
    int h;
    hurtboxType hurtType;
} hurtbox;

typedef struct {
    hurtbox* boxes;  //hurtboxes for the given model
} model;

typedef struct {
    hitbox* boxes;  //hitboxes for the given attack
    int frameLength;  //how long the animation lasts
    int damage;  //how much damage the attack does upon connecting
    int knockback;  //how much knockback the attack deals upon landing
} attack;
