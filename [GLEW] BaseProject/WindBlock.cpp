#include "WindBlock.h"

WindBlock::WindBlock(float x,float y, float w, float h):
    Object(x,y,w,h,0.6f,0.1f,0.6f){
    moving = false;
    floating = true;
}

