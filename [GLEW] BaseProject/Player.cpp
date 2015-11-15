#include "Player.h"
#include <iostream>

Player::Player(float x,float y):Object(x,y,0.5f,0.5f,1,1,1)
{
    moving = true;
    hasJumped = false;
}

void Player::jump()
{
	if (!hasJumped)
	{
		objVec.setYVec(0.25f);
		getVector()->addVector(objVec);
		hasJumped = true;
	}
}

void Player::land()
{
    hasJumped = false;
}

void Player::moveLeft()
{
	// Generate a vector
	VectorPhysics leftVector;
	leftVector.setXVec(0.1f);
	//leftVector.setYVec(objVec.getYVec());

	getVector()->subtractVector(leftVector); // Assign Vector 
	//getVector()->subtractVector(objVec); <- this is not working why :(
	//objVec.setXVec(-0.1f);
	// TODO:
}

void Player::moveRight()
{
	// Generate a vector
	VectorPhysics rightVector;
	rightVector.setXVec(0.1f);
	//rightVector.setYVec(objVec.getYVec());

	getVector()->addVector(rightVector); // Assign Vector 
	// TODO:
	//objVec.setXVec(0.1f);
}

void Player::haltHorizontal()
{
	// TODO:
	objVec.setXVec(0.0f);
}

void Player::setY(float val)
{
    yPos = val;
    transform.GetPos()->y = yPos;
}

void Player::setX(float val)
{
    xPos = val;
    transform.GetPos()->x = xPos;
}
