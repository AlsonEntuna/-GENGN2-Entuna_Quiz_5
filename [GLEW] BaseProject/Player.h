#ifndef PLAYER_H
#define	PLAYER_H

#include "Object.h"
#include <SFML/OpenGL.hpp>

class Player: public Object
{
    public:
        Player(float x,float y);
        void jump();
        void land();
        void moveLeft();
        void moveRight();
        void haltHorizontal();
        void setY(float val);
        void setX(float val);
    private:
        bool hasJumped;
};

#endif /* PLAYER_H */
