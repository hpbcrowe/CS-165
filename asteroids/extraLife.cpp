/**************************************************************************************************
* EXTRA LIFE.CPP
*  IMPLEMENTATION OF THE EXTRA LIFE METHODS  CONSTRUCTORS AND HIT
***************************************************************************************************/

#include "extraLife.h"



/*************************************************************************************************
*  EXTRALIFE :: EXTRALIFE
*  Non Default constructor
**************************************************************************************************/

ExtraLife::ExtraLife(const Point &point, const Velocity & velocity)
{
	//	setPoint(Point(random(-200, 200)));  //Starting point
	setPoint(point);  //Starting point
	setVelocity(velocity);
}

/*************************************************************************************************
* Rock :: HIT
*
**************************************************************************************************/
int ExtraLife::hit()
{
	kill();
	return 1;
	 
}