#ifndef SOLID_BLOCK_H
#define	SOLID_BLOCK_H

#include "Object.h"
#include <SFML/OpenGL.hpp>

class SolidBlock: public Object
{
    public:
        SolidBlock(float x,float y, float w, float h);
};

#endif /* SOLID_BLOCK_H */
