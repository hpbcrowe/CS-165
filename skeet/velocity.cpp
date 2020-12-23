/******************************************************************************
 * Source File:
 *    Velocity :
 * Author:
 *    Ben Crowe
 * Summary: This provides the movement  by providing a a point
 * that the object moves to dX (horizontal) or dY (vertical) when it is added
 * to the point it was previously at from the Point class x and y
 *****************************************************************************/

#include "velocity.h"

 /******************************************************************************
 * CONSTRUCTORS VELOCITY
 ******************************************************************************/

Velocity::Velocity()
{
}

Velocity::Velocity(const float &dx, const float &dy)
{
	setDx(dx);
	setDy(dy);
}

/*******************************************************************************
* Velocity:: SET DX
*******************************************************************************/
void Velocity::setDx(const float &dx)
{
	this->dx =  dx;
}

/*******************************************************************************
* Velocity::SET DY
********************************************************************************/
void Velocity::setDy(const float &dy)
{
	this->dy =  dy;
}


