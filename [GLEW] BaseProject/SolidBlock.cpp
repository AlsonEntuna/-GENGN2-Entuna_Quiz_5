#include "SolidBlock.h"

SolidBlock::SolidBlock(float x,float y, float w, float h):
    Object(x,y,w,h,0.4f,0.4f,0.4f){
    moving = false;
    floating = true;
}

