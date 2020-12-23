/***********************************************************************
 * Header File:
 *    Extra Life, rock that will give player extra life
 * Author:
 *   Ben Crowe
 * Summary:
 *    how to get more lives
 ************************************************************************/




#ifndef Extra_Life_H
#define Extra_Life_H

#include "rock.h"

constexpr int MEDIUM_ROCK_POINT = 3;


class ExtraLife : public Rock

{
public:
	/***************************************************************************
	* DEFAULT CONSTRUCTOR
	****************************************************************************/

	ExtraLife() : Rock() {}

	/****************************************************************************
	* NON DEFAULT CONSTRUCTOR
	*****************************************************************************/
	ExtraLife(const Point &point, const Velocity &velocity);


	/*************************************************************************************************
	* DRAW
	* Draw will be a virtual function when derived classes are created.
	**************************************************************************************************/
	virtual void draw() const override
	{
		
		drawLander(point);
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
	virtual int freeLife()
	{
		return 1;
	}

private:

};

#endif // EXTRA_LIFE_H
