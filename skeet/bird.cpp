/*************************************************************************************************
*  File: bird.cpp
*  Author:
*      Ben Crowe
*  Description:
*     Base class for all of the birds
*
**************************************************************************************************/


#include "bird.h"

/*************************************************************************************************
*  BIRD :: BIRD
*  Non Default constructor
**************************************************************************************************/

Bird::Bird(const Point &point) 
{
	setPoint(point);  //Starting point
	setVelocity(Velocity(VEL_X, VEL_Y)); //Starting speed
}

/*************************************************************************************************
* BIRD :: DRAW
*
**************************************************************************************************/
void Bird::draw()
{
	drawCircle(point, RADIUS);  //Draw a circle with a 15 pixel radius
}

/*************************************************************************************************
* BIRD :: HIT
*
**************************************************************************************************/
int Bird::hit()
{
	kill();
	return 1;

	
}
