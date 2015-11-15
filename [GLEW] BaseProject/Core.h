#ifndef CORE_H
#define	CORE_H

#include "Object.h"
#include <GL/glew.h>
#include <math.h>
#include <SFML/Window.hpp>

class Core{
    public:
        void init();
        bool isAlive();
        void pollEvent();
        void clear();
        void draw();
        bool isCollision(Object& objA, Object& objB);
    private:
        float timePerFrame;
        sf::Window window;
        sf::Clock clock;
};

#endif /* CORE_H */
