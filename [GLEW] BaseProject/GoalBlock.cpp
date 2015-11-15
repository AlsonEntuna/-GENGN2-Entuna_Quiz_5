#include "GoalBlock.h"

GoalBlock::GoalBlock(float x,float y, float w, float h):Object(x,y,w,h,1.0f,1.0f,0.0f)
{
    moving = false;
    floating = true;
}
