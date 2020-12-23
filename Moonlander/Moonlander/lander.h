/*************************************************************************
 * Header File:
 *    LANDER: 
 * Author:
 *    Ben Crowe
 * Summary:
 *  This class pulls in a Point object to give the location of the lander
 *  It also uses a Velocity object to calculate the movement of the lander
 *************************************************************************/


#ifndef LANDER_H 
#define LANDER_H
#include <iostream>
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
constexpr auto THRUST_Y = .3;
constexpr auto THRUST_X = .1;
constexpr auto LANDER_Y = 150;
constexpr auto X_FUEL_USE = 1;
constexpr auto Y_FUEL_USE = 3;


class Lander
{
public:
/********************************************************************************
* CONSTRUCTOR
*  
*********************************************************************************/
	Lander(); 

/*********************************************************************************
* GETTERS
**********************************************************************************/
	Point getPoint() const { return point; }
	Velocity getVelocity() const { return velocity; }
	bool isAlive() const { return alive; }
	bool isLanded() const { return land; }
	int getFuel() const { return fuel; }
	bool canThrust() const { return true; }
	bool canScreenWrap() const { return true; }

/**********************************************************************************
* SETTERS
***********************************************************************************/
	void setLanded(const bool &land);
	void setAlive(const bool &alive);
	void setFuel(const int &fuel);
	void setPoint(const Point &point);
	void setVelocity(const Velocity &velocity);

/**********************************************************************************
* APPLY GRAVITY
* Pushes the lander towards the ground
***********************************************************************************/
	void applyGravity(const float &gravity);

/**********************************************************************************
* APPLY THRUST LEFT
* CHANGES MOMENTUM TOWARDS THE RIGHT WHEN LEFT THRUSTER IS APPLIED
***********************************************************************************/
	void applyThrustLeft();

/**********************************************************************************
* APPLY THRUST RIGHT
* CHANGES MOMENTUM TOWARDS THE LEFT WHEN RIGHT THRUSTER IS APPLIED
***********************************************************************************/
	void applyThrustRight();

/**********************************************************************************
* APPLY THRUST BOTTOM
* CHANGES THE MOMENTUM AGAINST GRAVITY WHEN THIS IS APPLIED
***********************************************************************************/
	void applyThrustBottom();

/**********************************************************************************
* ADVANCE
*
***********************************************************************************/
	void advance();

/**********************************************************************************
* DRAW
*
***********************************************************************************/
	void draw() const;

private:
	Point point;
	Velocity velocity;
	int fuel;
	float gravity;
	bool land;
	bool alive;
	


/**********************************************************************************
* DESTRUCTOR
************************************************************************************/
	
};

#endif //LANDER.H
