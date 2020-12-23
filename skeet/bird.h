/***************************************************************************************************
* File: bird.h
* Author: Ben Crowe
* Description:
*   base class for the birds
*
****************************************************************************************************/

#ifndef BIRD_H
#define BIRD_H

#include "flyingObject.h"

const int ORIG_X = 3;  //Starting x coordinate
const int ORIG_Y = 1;  //Starting y coordinate
const int RADIUS = 15;
const int VEL_X = 3;
const int VEL_Y = 1;
constexpr int VEL_T = 3;


class Bird : public FlyingObject
{
public:
	/************************************************************************************************
	*  Default Constructor
	*
	************************************************************************************************/
	 Bird() { Point origin; setVelocity(Velocity(ORIG_X, ORIG_Y));  //Start Bird on left side of screen with 
	}                                                    //this velocity  

	/***********************************************************************************************
	* Non Default Constructor
	*
	***********************************************************************************************/
	Bird(const Point &point);

	

	/*************************************************************************************************
	* DRAW
	* Draw will be a virtual function when derived classes are created.
	**************************************************************************************************/
	virtual void draw();

	/*************************************************************************************************
	* HIT
	* Scores damage
	**************************************************************************************************/
	virtual int hit();

protected:
	int hitPoints;




};




#endif //BIRD_H

