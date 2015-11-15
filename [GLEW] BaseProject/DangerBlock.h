/*
    No need to comment this file...
*/
#ifndef DANGER_BLOCK_H
#define	DANGER_BLOCK_H

#include "Object.h"
#include <SFML/OpenGL.hpp>

class DangerBlock: public Object{
    public:
        DangerBlock(float x,float y, float w, float h);
};

#endif /* DANGER_BLOCK_H */
