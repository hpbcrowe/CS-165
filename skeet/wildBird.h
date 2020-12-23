/***************************************************************************************************
* File: wildBird.h
* Author: Ben Crowe
* Description:
* Class for wild Bird, When hit bird will either double your score or divide it by two
****************************************************************************************************/

#ifndef WILD_BIRD_H
#define WILD_BIRD_H

#include "bird.h"
#include "game.h"


const int W_WARNING_X = 95;
const int W_WARNING_Y = 0;
//This Class is above and beyond

class WildBird : public Bird
{
public:
	/************************************************************************************************
	*  Constructor
	*   Default
	************************************************************************************************/
	WildBird();


	/************************************************************************************************
	* Non Default Constructor
	*
	************************************************************************************************/
	WildBird(const Point &point);

	/**********************************************************************************************
	* GETTER
	*
	**********************************************************************************************/
	int getDice()const { return dice; }
	

	/************************************************************************************************
	* SETTER
	*
	*************************************************************************************************/
	void setDice(const int &dice);

	/*************************************************************************************************
	* DRAW
	*
	**************************************************************************************************/
	virtual void draw()

	{
		Point warning;
		warning.setX(warning.getX() - W_WARNING_X);
		warning.setY(warning.getY() + W_WARNING_Y);   //This text is above and beyond
		drawLander(point);
		
		drawText(warning, "Roll the Dice +10 or -10 points"); //wildBird Description
		
	}

	/*************************************************************************************************
	* HIT
	*
	**************************************************************************************************/
	virtual int hit();


protected:
	int dice;

};




#endif //WILD_BIRD_H

