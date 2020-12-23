/***************************************************************************************************
* File: sacredBird.h
* Author: Ben Crowe
* Description:
* Class for sacred bird which shouldn't be shoot and if it is, points will be deducted   
* -10 points
****************************************************************************************************/

#ifndef SACRED_BIRD_H
#define SACRED_BIRD_H

#include "bird.h"
const int WARNING_X = 85;
const int WARNING_Y = 0;


class SacredBird : public Bird
{
public:
	/************************************************************************************************
	*  Constructor
	*   Default
	************************************************************************************************/
	SacredBird();
	
															 
	/************************************************************************************************
	* Non Default Constructor
	*
	************************************************************************************************/
	SacredBird(const Point &point);

	/*************************************************************************************************
	* DRAW
	*
	**************************************************************************************************/
	virtual void draw() 
		
	{
		Point warning;                                    //This text is above and beyond
		warning.setX(warning.getX() - WARNING_X);
		warning.setY(warning.getY() + WARNING_Y);
		drawSacredBird(point, 15);               
		
		drawText(warning, "Warning When Hit -10 Points"); //Warning text not to hit bird
	}

	/*************************************************************************************************
	* HIT
	*
	**************************************************************************************************/
	virtual int hit();


};




#endif //SACRED_BIRD_H



