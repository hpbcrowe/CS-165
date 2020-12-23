/*********************************************************************
 * File: ship.cpp
 * Description: Contains the implementaiton of the ship class
 *  methods.
 *
 *********************************************************************/





#include "ship.h"

// Put your ship methods here







/*******************************************************************************
* SHIP :: SHIP
*  Default Constructor  start out alive 
********************************************************************************/

Ship::Ship()
{
	alive = true;
	thrust = false;
	shipLife = INITIAL_LIFE;
	
	point.addY(SHIP_Y);

}


/*******************************************************************************
* VOID SHIP::SET THRUST
*
********************************************************************************/

void Ship::setThrust(const bool &thrust)
{
	this->thrust = thrust;
}

/*******************************************************************************
* VOID Ship::SET SHIP LIFE
*
********************************************************************************/
void Ship::setShipLife(const int &shipLife)
{
	this->shipLife = shipLife;
}

/*********************************************************************************
* VOID SHIP:: ROTATE LEFT
* ROTATES THE SHIP ON IT'S CENTER TO THE LEFT
**********************************************************************************/
void Ship::rotateLeft()
{
	angle -= ROTATE_AMOUNT;

	
}

/*********************************************************************************
* VOID SHIP :: ROTATE  RIGHT
* ROTATES THE SHIP ON IT'S CENTER TO THE LEFT
**********************************************************************************/
void Ship::rotateRight()
{
	angle += ROTATE_AMOUNT;
}

/*********************************************************************************
* VOID SHIP :: APPLY THRUST BOTTOM
* MOVES THE SHIP IN THE DIRECTION IT'S POINTING WHEN APPLIED
**********************************************************************************/
void Ship::applyThrustBottom()
{
	setPoint(point);
	float dx = THRUST_AMOUNT * (-cos(3.144 / 180 * angle)); //This was given to us
	float dy = THRUST_AMOUNT * (sin(3.144 / 180 * angle));
	// four if statements that check dx and dy against the speed limit;
	if (dx > speed_limit)
		dx = speed_limit;
	if (dx < -speed_limit)
		dx = -speed_limit;
	if (dy > speed_limit)
		dy = speed_limit;
	if (dy < -speed_limit)
		dy = speed_limit;

	velocity.setDx(dx); 
	velocity.setDy(dy);

}

/**********************************************************************************
* VOID SHIP :: HIT
* KILLS THE SHIP AND RESPAWNS IT IN THE CENTER OF THE SCREEN IF THERE ARE STILL 
* LIVES
***********************************************************************************/
void Ship::hit()
{
	if (getShipLife() > 0)
	{
		kill();
		setAlive(true);
		setPoint(Point());
		setVelocity(Velocity());
	}
	else
	{		
		kill();
	}

}


