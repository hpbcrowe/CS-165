/***********************************************************************
 * Header File:
 *    Small Rock : The representation of small asteroids
 * Author:
 *   Ben Crowe
 * Summary:
 *    Code to put small asteroids on the screen
 ************************************************************************/


#ifndef Small_Rock_H
#define Small_Rock_H

#include "rock.h"
constexpr int SMALL_ROCK_POINT = 5;

class SmallRock : public Rock

{
public:
	/***************************************************************************
	* DEFAULT CONSTRUCTOR
	****************************************************************************/

	SmallRock() : Rock() {}

	/****************************************************************************
	* NON DEFAULT CONSTRUCTOR
	*****************************************************************************/
	SmallRock(const Point &point, const Velocity &velocity);


	/*************************************************************************************************
	* DRAW
	* Draw will be a virtual function when derived classes are created.
	**************************************************************************************************/
	virtual void draw() const override
	{
		static int rotation = 0;    //Help from Daniel static variable
		rotation += SMALL_Rock_SPIN;  //Rotation of asteroid 
		drawSmallAsteroid(point, rotation);
	}

	/*************************************************************************************************
	* HIT
	* Scores damage
	**************************************************************************************************/
	virtual int hit();

	/*************************************************************************************************
	* SCORE POINTS
	* Returns points when rock is hit
	**************************************************************************************************/
	virtual int scorePoints()
	{
		return SMALL_ROCK_POINT;
	}

private:

};

#endif // SMALL_ROCK_H