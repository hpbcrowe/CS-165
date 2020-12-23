/*************************************************************************************************
*  File: wildBird.cpp
*  Author:
*      Ben Crowe
*  Description:
*   Class for wild Bird, When hit bird will either double your score or divide it by two
*
**************************************************************************************************/


#include "wildBird.h"

/*************************************************************************************************
* WILDBIRD :: WILDBIRD
* DEFAULT CONSTRUCTOR
*************************************************************************************************/
WildBird::WildBird()
{
	setVelocity(Velocity(random(3, 7), (getPoint().getY() / -75.0)));
}
/*************************************************************************************************
* WILDBIRD :: WILDBIRD
* NON DEFAULT CONSTRUCTOR
*************************************************************************************************/
WildBird::WildBird(const Point &point)
{
	setPoint(point);  //Starting point
	setVelocity(Velocity(random(3, 7), (getPoint().getY() / -75.0))); //Starting speed Daniels help
}


/*************************************************************************************************
* VOID WILDBIRD :: SET DICE
*
**************************************************************************************************/
void WildBird::setDice(const int &dice)
{
	this->dice = dice;
}

/*************************************************************************************************
* WILDBIRD :: HIT
*
**************************************************************************************************/
int WildBird::hit()
{

	kill();
	int dice = random(1, 3);
	if (dice == 1)

		return 10;

	else
		return -10;
}


	
	


