/**************************************************************************************************
* MEDIUM ROCK.CPP
*  IMPLEMENTATION OF THE MEDIUM ROCK METHODS  CONSTRUCTORS AND HIT
***************************************************************************************************/

#include "mediumRock.h"


/*************************************************************************************************
*  MEDIUMROCK :: MEDIUMROCK
*  Non Default constructor
**************************************************************************************************/

MediumRock::MediumRock(const Point &point, const Velocity & velocity)
{
//	setPoint(Point(random(-200, 200)));  //Starting point
	setPoint(point);  //Starting point
	setVelocity(velocity);
}

/*************************************************************************************************
* Rock :: HIT
*
**************************************************************************************************/
int MediumRock::hit()
{
	kill();
	return 2;
}