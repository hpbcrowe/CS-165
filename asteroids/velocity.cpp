#include "velocity.h"


// Put your velocity methods here

/******************************************************************************
* CONSTRUCTORS VELOCITY
******************************************************************************/

Velocity::Velocity(): dx(0.0), dy(0.0)
{}

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
	this->dx = this->dx + dx;
}

/*******************************************************************************
* Velocity::SET DY
********************************************************************************/
void Velocity::setDy(const float &dy)
{
	this->dy = this->dy + dy;
}