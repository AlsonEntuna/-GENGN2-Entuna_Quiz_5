/*
    No need to comment this file...
*/
#ifndef LIFE_BLOCK_H
#define	LIFE_BLOCK_H

#include "Object.h"
#include <SFML/OpenGL.hpp>

class LifeBlock: public Object{
    public:
        LifeBlock(float x,float y, float w, float h);
};

#endif /* LIFE_BLOCK_H */
