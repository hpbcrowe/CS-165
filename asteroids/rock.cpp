/*********************************************************************
 * File: Rock.cpp
 * Description: Contains the implementaiton of the Rock class
 *  methods. And the Big, Medium and Small Rock children
 *
 *********************************************************************/

#include "rock.h"

// Put your Rock methods here

/*************************************************************************************************
*  Rock :: Rock
*  Non Default constructor
**************************************************************************************************/

Rock::Rock(const Point &point, const Velocity &velocity): hitPoints(0) 
{
	setPoint(point);  //Starting point
	setVelocity(velocity); //Starting speed
}
