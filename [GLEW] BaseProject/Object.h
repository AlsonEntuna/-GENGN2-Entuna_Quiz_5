#ifndef OBJECT_H
#define	OBJECT_H

#include <GL/glew.h>
#include <string>
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"
#include "ModelTransform.h"
#include "VectorPhysics.h"
#include <iostream>

using namespace std;

class Object
{
    public:
        Object(float x,float y,float w,float h, float r, float g, float b);
        void draw(const Camera& camera);
        void update();
        float getX();
        float getY();
        float getWidth();
        float getHeight();
        void setFloating(bool value);
        bool isFloating();
        void setMoving(bool value);
        bool isMoving();
        VectorPhysics* getVector();
        bool isColliding(Object &rectB);
        ModelTransform* getTransform();
    protected:
        float xPos;
        float yPos;
        float width;
        float height;
        bool floating;  //means it is affected by gravity
        bool moving;    //means it updates
        VectorPhysics objVec;
        Mesh mesh;
        Shader shader;
        ModelTransform transform;

        float getLeft();
        float getRight();
        float getBottom();
        float getTop();
};

#endif /* OBJECT_H */
