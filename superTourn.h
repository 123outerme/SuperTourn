#include "outermeSDL.h"

typedef enum {
    none,  //0  -- no hitbox at all
    noPriority,  //1  -- only causes knockback on a sensitive hurtbox, has lowest priority
    lowPriority,  //2  -- only causes knockback on sensitive/normal hurtboxes, only beats noPriority
    midPriority,  //3  -- only causes knockback on sensitive/normal hurtboxes, only loses to highPriority
    highPriority,  //4 -- causes knockback on all hurtboxes, doesn't lose
    grab,  //5  -- upon landing on a non-invincible hitbox, starts a grab
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
    int x;
    int y;
    int w;
    int h;
    int HP;
    int maxHP;
    sprite* sprites;  //x&y coords are in relatives
    int dmgMult;
    int spdMult;
} fighter;

typedef struct {
    hitbox* boxes;  //hitboxes for the given attack
    int frameLength;  //how long the animation lasts
    int damage;  //how much damage the attack does upon connecting
    int knockback;  //how much knockback the attack deals upon landing
} attack;

void initConfig(char* filePath);  //inits a new config file
void initHurtbox(hurtbox* boxptr, int relX, int relY, int w, int h, hurtboxType type);  //constructs a new hurtbox struct
void initHitbox(hitbox* boxptr, int relX, int relY, int w, int h, int frameOut, int activeLength, hitboxType type);  //constructs a new hitbox struct
void initModel(model* modelPtr, hurtbox* boxes);  //constructs a new model struct
void initAttack(attack* attackPtr, hitbox* boxes, int frameLength, int dmg, int kb);  //constructs a new attack struct
int aMenu(int cursorID, char* title, char* opt1, char* opt2, char* opt3, char* opt4, char* opt5, const int options, int curSelect, SDL_Color bgColor, SDL_Color titleColorUnder, SDL_Color titleColorOver, SDL_Color textColor, bool border, bool isMain);

#define SIZE_OF_SCANCODE_ARRAY 7
int CUSTOM_SCANCODES[SIZE_OF_SCANCODE_ARRAY];
#define SC_UP CUSTOM_SCANCODES[0]
#define SC_DOWN CUSTOM_SCANCODES[1]
#define SC_LEFT CUSTOM_SCANCODES[2]
#define SC_RIGHT CUSTOM_SCANCODES[3]
#define SC_INTERACT CUSTOM_SCANCODES[4]
#define SC_MENU CUSTOM_SCANCODES[5]
#define SC_ATTACK CUSTOM_SCANCODES[6]

int FPS, targetTime;
