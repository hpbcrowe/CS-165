/*************************************************************************************************
*  File: sacredBird.cpp
*  Author:
*      Ben Crowe
*  Description:
*    Class for sacred bird which shouldn't be shoot and if it is, points will be deducted   
* -10 points
*
**************************************************************************************************/


#include "sacredBird.h"

/*************************************************************************************************
* SACREDBIRD :: SACREDBIRD
* DEFAULT CONSTRUCTOR
*************************************************************************************************/
SacredBird::SacredBird()
{
	setVelocity(Velocity(random(3, 7), (getPoint().getY() / -75.0)));
}
/*************************************************************************************************
* SACREDBIRD :: SACREDBIRD
* NON DEFAULT CONSTRUCTOR
*************************************************************************************************/
SacredBird ::SacredBird(const Point &point)
{
	setPoint(point);  //Starting point
	setVelocity(Velocity(random(3, 7), (getPoint().getY() / -75.0))); //Starting speed Daniels help
}


/*************************************************************************************************
* BIRD :: HIT
*
**************************************************************************************************/
int SacredBird::hit()
{
	kill();
	return -10;

	Point oops;
	oops.setX(oops.getX() - WARNING_X);
	oops.setY(oops.getY() + WARNING_Y);
	
	drawText(oops, "Why did you do that? -10 Points");

}
