#include "VectorPhysics.h"

VectorPhysics::VectorPhysics()
{
    xVec = yVec = 0;
}

void VectorPhysics::addVector(VectorPhysics vec)
{
	xVec += vec.getXVec();
	yVec += vec.getYVec();
	cout << "Adding Vector X: " << xVec << " Y: " << yVec << endl;
}

void VectorPhysics::subtractVector(VectorPhysics vec)
{
	xVec -= vec.getXVec();
	yVec -= vec.getYVec();
	cout << "Subracting Vector X: " << xVec << " Y:" << yVec << endl;
}

void VectorPhysics::setXVec(float val)
{
    xVec = val;
}

void VectorPhysics::setYVec(float val)
{
    yVec = val;
}

float VectorPhysics::getXVec()
{
    return xVec;
}

float VectorPhysics::getYVec()
{
    return yVec;
}

