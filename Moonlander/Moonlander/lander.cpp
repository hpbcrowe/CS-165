/***********************************************************************
 * Implementation File:
 *    LANDER : A class representing the lunar lander
 * Author:
 *    Ben Crowe
 * Summary:
 *    Handles the position of the lunar lander
 ************************************************************************/






#include "lander.h"

//Changed initial position of lander to +150 on y axis
//less chance of starting out crashed in the ground.

/*******************************************************************************
* LANDER :: LANDER
*  Default Constructor  start out alive and not in the ground and at point y =
*  150.
********************************************************************************/

Lander::Lander()
{
	alive = true;
	land = false;
	point.addY(LANDER_Y); 
	
}

/*******************************************************************************
* VOID LANDER::SET LANDED
* 
********************************************************************************/
void Lander::setLanded(const bool &land)
{
	this->land = land;
}

/*******************************************************************************
* VOID LANDER::SET ALIVE
*
********************************************************************************/
void Lander::setAlive(const bool &alive)
{
	this->alive = alive;
}

/********************************************************************************
* VOID LANDER::SET FUEL
*
*********************************************************************************/
void Lander::setFuel(const int &fuel)
{
	this->fuel = fuel;
}

void Lander::setPoint(const Point & point)
{
	this->point = point;
}

void Lander::setVelocity(const Velocity & velocity)
{
	this->velocity = velocity;
}

/********************************************************************************
* VOID LANDER:: APPLY GRAVITY
* Applies the force of gravity to the lander
*********************************************************************************/
void Lander::applyGravity(const float &gravity)
{
	velocity.setDy(-gravity);
}

/*********************************************************************************
* VOID LANDER:: APPLY THRUST LEFT
* Changes momentum to the right when thrust is applied
**********************************************************************************/
void Lander::applyThrustLeft()
{
	if (fuel > 0)
	{
		velocity.setDx(THRUST_X);
		setFuel(fuel - X_FUEL_USE);
	}

}

/*********************************************************************************
* VOID LANDER :: APPLY THRUST RIGHT
* Changes momentum to the left when thrust is applied
**********************************************************************************/
void Lander::applyThrustRight()
{
	if (fuel > 0)
	{
		velocity.setDx( - THRUST_X);
		setFuel(fuel - X_FUEL_USE);
	}
}

/*********************************************************************************
* VOID LANDER :: APPLY THRUST BOTTOM
* Reverses force of gravity when applied
**********************************************************************************/
void Lander::applyThrustBottom()
{
	if (fuel > 3)
	{
		velocity.setDy(THRUST_Y);
			setFuel(fuel - Y_FUEL_USE);
	}
}

/*********************************************************************************
* VOID LANDER :: ADVANCE
* 
**********************************************************************************/
void Lander::advance()
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());
	

}

/*********************************************************************************
* VOID LANDER :: DRAW
*
**********************************************************************************/
void Lander::draw() const
{
	drawLander(point);
}

