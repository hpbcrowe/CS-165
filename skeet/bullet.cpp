/*************************************************************************************************
*  File: bullet.cpp
*  Author:
*      Ben Crowe
*  Description:
*     Bullet that flies out of rifle
*
**************************************************************************************************/


#include "bullet.h"



	




/*************************************************************************************************
* BULLET :: DRAW
*
**************************************************************************************************/
void Bullet :: draw()
{
    drawDot(point);
}

/**************************************************************************************************
* BULLET :: FIRE
*
**************************************************************************************************/
void Bullet::fire(const Point &point, const float &angle)
{
	setPoint(point); //Daniel helped me with this
	
	velocity.setDx(BULLET_SPEED * (-cos(3.144 / 180 * angle))); //This was given to us
	velocity.setDy( BULLET_SPEED * (sin(3.144 / 180 * angle)));

	
	


}