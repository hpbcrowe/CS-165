/***************************************************************************************************
* File: standardBird.h
* Author: Ben Crowe
* Description:
*   standardBird class, easiest bird to hit and destroy only 1 hit and 1 point awarded
*
****************************************************************************************************/

#ifndef STANDARD_BIRD_H
#define STANDARD_BIRD_H

#include "bird.h"
const int STANDARD_RADIUS = 15;



class StandardBird : public Bird
{
public:
	/************************************************************************************************
	*  Constructors
	*
	************************************************************************************************/
	StandardBird();
	
	StandardBird(const Point &point);



	/*************************************************************************************************
	* DRAW
	* Draw will be a virtual function when derived classes are created.
	**************************************************************************************************/
	virtual void draw() const
		
	{
		drawCircle(point, STANDARD_RADIUS);
	}

	/*************************************************************************************************
	* HIT
	* Scores damage
	**************************************************************************************************/
	virtual int hit()
		
	{
		kill();

		return 1;
	}


};




#endif //STANDARD_BIRD_H
