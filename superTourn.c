#include "superTourn.h"

void initHurtbox(hurtbox* boxptr, int relX, int relY, int w, int h, hurtboxType type)
{
    boxptr->relX = relX;
    boxptr->relY = relY;
    boxptr->w = w;
    boxptr->h = h;
    boxptr->hurtType = type;
}

void initHitbox(hitbox* boxptr, int x, int y, int w, int h, int frameOut, int activeLength, hitboxType type)
{
    boxptr->x = x;
    boxptr->y = y;
    boxptr->w = w;
    boxptr->h = h;
    boxptr->onFrame = 0;
    boxptr->frameOut = frameOut;
    boxptr->activeLength = activeLength;
    boxptr->hitType = type;
}

void initModel(model* modelPtr, hurtbox* boxes)
{
    modelPtr->boxes = boxes;
}

void initAttack(attack* attackPtr, hitbox* boxes, int frameLength, int dmg, int kb)
{
    attackPtr->boxes = boxes;
    attackPtr->frameLength = frameLength;
    attackPtr->damage = dmg;
    attackPtr->kb = kb;
}
