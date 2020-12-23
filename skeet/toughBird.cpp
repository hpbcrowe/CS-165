/*************************************************************************************************
*  File: toughBird.cpp
*  Author:
*      Ben Crowe
*  Description:
*     Class for tough Bird it takes three hits to destroy. 5 points can be earned 
*
*
**************************************************************************************************/


#include "toughBird.h"


/*************************************************************************************************
* TOUGHBIRD :: TOUGHBIRD
*  DEFAULT CONSTRUCTOR
**************************************************************************************************/
ToughBird::ToughBird() 
{
	setToughBirdHealth(3);
	setVelocity(Velocity(random(2, 5), (getPoint().getY() / -100.00)));
}

/*************************************************************************************************
* TOUGHBIRD :: TOUGHBIRD
* NON DEFAULT CONSTRUCTOR
**************************************************************************************************/
ToughBird::ToughBird(const Point &point)
{
	setPoint(point);  //Starting point
	setToughBirdHealth(3);
	setVelocity(Velocity(random(2, 5), (getPoint().getY() / -100.00)));
}

/*************************************************************************************************
* VOID TOUGHBIRD :: SET TOUGHBIRDHEALTH
*
**************************************************************************************************/
void ToughBird::setToughBirdHealth(const int &toughBirdHealth)
{
	this->toughBirdHealth = toughBirdHealth;
}



