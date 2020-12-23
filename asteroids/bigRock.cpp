/**************************************************************************************************
* BIG ROCK.CPP
*  IMPLEMENTATION OF THE BIG ROCK METHODS  CONSTRUCTORS AND HIT 
***************************************************************************************************/

#include "bigRock.h"
#include <vector>


/*************************************************************************************************
*  BIGROCK :: BIGROCK
*  Non Default constructor
**************************************************************************************************/

BigRock::BigRock(const Point &point, const Velocity &velocity, int spin)
{
	//setPoint(Point(random(-200, 200)));  //Starting point
	setPoint(point);
	setVelocity(velocity);
	this->spin = spin;
}

/*************************************************************************************************
* Rock :: HIT
*
**************************************************************************************************/
int BigRock::hit()
{
	kill();
	

	return 1;
}