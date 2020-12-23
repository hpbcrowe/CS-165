/***********************************************************************
 * Header File:
 *    Medium Rock : The representation of medium asteroids
 * Author:
 *   Ben Crowe
 * Summary:
 *    Code to put medium asteroids on the screen
 ************************************************************************/




#ifndef Medium_Rock_H
#define Medium_Rock_H

#include "rock.h"

constexpr int MEDIUM_ROCK_POINT = 3;


class MediumRock : public Rock

{
public:
	/***************************************************************************
	* DEFAULT CONSTRUCTOR
	****************************************************************************/

	MediumRock() : Rock() {}

	/****************************************************************************
	* NON DEFAULT CONSTRUCTOR
	*****************************************************************************/
	MediumRock(const Point &point, const Velocity &velocity);


	/*************************************************************************************************
	* DRAW
	* Draw will be a virtual function when derived classes are created.
	**************************************************************************************************/
	virtual void draw() const override
	{
		static int rotation = 0;    //Help from Daniel static variable
		rotation += MEDIUM_Rock_SPIN;  //Rotation of asteroid 
		drawMediumAsteroid(point, rotation);
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
		return MEDIUM_ROCK_POINT;
	}

private:

};

#endif // MEDIUM_ROCK_H
