/*
    No need to comment this file...
*/
#ifndef WIND_BLOCK_H
#define	WIND_BLOCK_H

#include "Object.h"
#include <SFML/OpenGL.hpp>

class WindBlock: public Object{
    public:
        WindBlock(float x,float y, float w, float h);
};

#endif /* WIND_BLOCK_H */
