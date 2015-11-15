#ifndef VECTOR_PHYSICS_H
#define VECTOR_PHYSICS_H

#include <SFML/OpenGL.hpp>
#include <iostream>

using namespace std;

class VectorPhysics
{
    public:
        VectorPhysics();
        void addVector(VectorPhysics vec);
        void subtractVector(VectorPhysics vec);
        void setXVec(float val);
        void setYVec(float val);
        float getXVec();
        float getYVec();
    private:
        float xVec;
        float yVec;
};

#endif /* VECTOR_PHYSICS_H */
