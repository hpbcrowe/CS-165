/*********************************************************************
 * File: flyingObject.cpp
 * Description: Contains the implementation of the flyingObject class
 *  methods.
 *
 *********************************************************************/

#include "flyingObject.h"

/****************************************************************************************************
* FLYING OBJECT :: SET POINT
*
*****************************************************************************************************/
void FlyingObject::setPoint(const Point &point)
{
	this->point = point;
}

void FlyingObject::setAlive(const bool &alive)
{
	this->alive = alive;
}

/****************************************************************************************************
*  FLYING OBJECT :: SET VELOCITY
*
****************************************************************************************************/
void FlyingObject::setVelocity(const Velocity &velocity)
{
	this->velocity = velocity;
}


/*************************************************************************************************
*  FLYING OBJECT :: KILL
*
**************************************************************************************************/
void FlyingObject::kill()
{
	alive = false;
}

/*************************************************************************************************
* FLYING OBJECT :: ADVANCE
*
**************************************************************************************************/
void FlyingObject::advance(Point topLeft, Point bottomRight)
{
	point.addY(velocity.getDy()); //moves flying objects
	point.addX(velocity.getDx());
	
	//My attempt at screen wrapping

	//Change x coordinates going off the screen
	//on either side to the opposite side
	if (point.getX() < topLeft.getX())
	{
		point.setX(bottomRight.getX());
	}

	if (point.getX() > bottomRight.getX())
	{
		point.setX(topLeft.getX());
	}

	//Change y coordinates going off the screen
	//to the opposite side.
	if (point.getY() > topLeft.getY())
	{
		point.setY(bottomRight.getY());
	}

	if (point.getY() < bottomRight.getY())
	{
		point.setY(topLeft.getY());
	}

}