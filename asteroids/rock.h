/***********************************************************************
 * Header File:
 *    Rock : The parent class for all rocks
 * Author:
 *    Ben Crowe
 * Summary:
 *  Will be used to make a vector of pointers, so there can be different   
 *  kinds of rocks 
 ************************************************************************/

#ifndef Rock_H
#define Rock_H

constexpr int BIG_Rock_SIZE = 16;
constexpr int MEDIUM_Rock_SIZE = 8;
constexpr int SMALL_Rock_SIZE = 4;
//using namespace rockData;

constexpr int BIG_Rock_SPIN = 2;
constexpr int MEDIUM_Rock_SPIN = 5;
constexpr int SMALL_Rock_SPIN = 10;

// Define the following classes here:
//   Rock
//   BigRock
//   MediumRock
//   SmallRock

#include "flyingObject.h"

class Rock : public FlyingObject
{
public:
	/************************************************************************************************
	*  Default Constructor
	*
	************************************************************************************************/
	Rock()   {	}

	/***********************************************************************************************
	* Non Default Constructor
	*
	***********************************************************************************************/
	Rock(const Point &point, const Velocity &velocity);

	/*************************************************************************************************
	* DRAW
	* Draw will be a virtual function when derived classes are created.
	**************************************************************************************************/
	virtual void draw() const = 0;

	/*************************************************************************************************
	* HIT
	* Creates damage
	**************************************************************************************************/
	virtual int hit() = 0;

	/*************************************************************************************************
	* SCORE POINTS
	* Returns points when rock is hit
	**************************************************************************************************/
	virtual int scorePoints() = 0;

protected:
	int hitPoints;
};


#endif // ROCK_H
