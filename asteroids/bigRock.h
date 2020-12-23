/**********************************************************************************
*Header File:
*   Big Rock CLASS for the largest asteroids
* Author:
*    Ben Crowe
* Summary:
*    Derived class from Rock
*    
*
**********************************************************************************/


#ifndef BIG_ROCK_H
#define BIG_ROCK_H

#include "rock.h"
constexpr int BIG_ROCK_POINTS = 1;





class BigRock : public Rock

{
public:
	/***************************************************************************
	* DEFAULT CONSTRUCTOR
	****************************************************************************/

	BigRock() : Rock() { }

	/****************************************************************************
	* NON DEFAULT CONSTRUCTOR
	*****************************************************************************/
	BigRock(const Point &point, const Velocity &velocity, int spin);


	/*************************************************************************************************
	* DRAW
	* Draw will be a virtual function when derived classes are created.
	**************************************************************************************************/
	virtual void draw() const
	{
		static int rotation = 0;    //Help from Daniel static variable

		if (spin <= 5)
		{
			rotation += BIG_Rock_SPIN;  //Rotation of asteroid 
		}
		else
		{
			rotation -= BIG_Rock_SPIN;  //Rotation of asteroid 
		}
		drawLargeAsteroid(point, rotation);
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
		return BIG_ROCK_POINTS;
	}



private:
	int spin;
};




#endif // BIG_ROCK_H

