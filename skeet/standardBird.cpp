/*************************************************************************************************
*  File: standardBird.cpp
*  Author:
*      Ben Crowe
*  Description:
*     Class for the main bird in game. 15px radius 1 point is awarded for hitting.
*
**************************************************************************************************/


#include "standardBird.h"

/*************************************************************************************************
* STANDARD BIRD :: STANDARD BIRD
* DEFAULT CONSTRUCTOR
**************************************************************************************************/
StandardBird::StandardBird()
{
	setVelocity(Velocity(random(3, 7), (getPoint().getY() / -75.0))); //Help from Daniel
}

/*************************************************************************************************
* STANDARDBIRD :: STANDARDBIRD 
* NON DEFAULT CONSTRUCTOR
**************************************************************************************************/
StandardBird::StandardBird(const Point &point)
{
	setPoint(point);  //Starting point
	setVelocity(Velocity(random(3, 7), (getPoint().getY() / -75.0))); //Help from Daniel
}
