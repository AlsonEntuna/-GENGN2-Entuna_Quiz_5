#include "Object.h"

Object::Object(float x,float y,float w,float h, float r, float g, float b){
    xPos = x;
    yPos = y;
    width = w/2;
    height = h/2;

    Vertex vertices[] = {
        Vertex(glm::vec3(-width,-height, -10.0f), glm::vec3(r,g,b)),
        Vertex(glm::vec3( width,-height, -10.0f), glm::vec3(r,g,b)),
        Vertex(glm::vec3(-width, height, -10.0f), glm::vec3(r,g,b)),
        Vertex(glm::vec3( width, height, -10.0f), glm::vec3(r,g,b)),
        Vertex(glm::vec3( width,-height, -10.0f), glm::vec3(r,g,b)),
        Vertex(glm::vec3(-width, height, -10.0f), glm::vec3(r,g,b))};

    std::string shaderFile("./res/basicShader");
    mesh.init(vertices,sizeof(vertices)/sizeof(vertices[0]));
    shader.init(shaderFile);

    transform.GetPos()->x = xPos;
    transform.GetPos()->y = yPos;
}

float Object::getX(){
    return xPos;
}

float Object::getY(){
    return yPos;
}

float Object::getWidth(){
    return width*2;
}

float Object::getHeight(){
    return height*2;
}

void Object::draw(const Camera& camera)
{
    shader.bind();
    shader.update(transform,camera);
    mesh.draw();
}

void Object::update()
{
    if(!floating)
	{
		VectorPhysics gravity;
		gravity.setYVec(0.05f);
		getVector()->subtractVector(gravity);
    }
    if(moving)
	{
        xPos += objVec.getXVec();
        yPos += objVec.getYVec();
        transform.GetPos()->x = xPos;
        transform.GetPos()->y = yPos;
    }
}

void Object::setFloating(bool value)
{
    floating = value;
}

bool Object::isFloating()
{
    return floating;
}

void Object::setMoving(bool value){
    moving = value;
}

bool Object::isMoving(){
    return moving;
}

VectorPhysics* Object::getVector()
{
    return &objVec;
}

float Object::getLeft()   { return xPos-width;  }
float Object::getRight()  { return xPos+width;  }
float Object::getTop()    { return yPos+height; }
float Object::getBottom() { return yPos-height; }

bool Object::isColliding(Object &rectB)
{
    return (getRight() >= rectB.getLeft() && getLeft() <= rectB.getRight()) &&
        (getTop() >= rectB.getBottom() && getBottom() <= rectB.getTop());
}

ModelTransform* Object::getTransform()
{
    return &transform;
}
