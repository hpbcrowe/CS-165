/*********************************************************************
 * File: bullet.cpp
 * Description: Implementation of the bullet methods
 *  
 *
 *********************************************************************/

#include "bullet.h"


// Put your bullet methods here

/**************************************************************************************************
* BULLET :: FIRE
*
**************************************************************************************************/
void Bullet::fire(const Point &point, const float &angle, const Velocity & originVelocity)
{
	setPoint(point); //Daniel helped me with this
	
	float dX = BULLET_SPEED * (-cos(3.144 / 180 * angle));
	float dY = BULLET_SPEED * (sin(3.144 / 180 * angle));
    velocity.setDx(dX + originVelocity.getDx()); //This was given to us
	velocity.setDy(dY + originVelocity.getDy());
}