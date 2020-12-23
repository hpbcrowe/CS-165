
/***************************************************************************************************
* File: toughBird.h
* Author: Ben Crowe
* Description:
*   Class for tough Bird it takes three hits to destroy. 5 points can be earned 
*
****************************************************************************************************/

#ifndef TOUGH_BIRD_H
#define TOUGH_BIRD_H

#include "bird.h"

const int HIT_BIRD = 1;
const int BONUS_X = 85;
const int BONUS_Y = 0;
const int TOUGH_RADIUS = 15;


class ToughBird : public Bird
{
public:
	/************************************************************************************************
	*  Constructors
	*  Default 
	************************************************************************************************/
	ToughBird();

	/***********************************************************************************************
	* Non Default Constructor
	*
	***********************************************************************************************/
	ToughBird(const Point &point);

	/**********************************************************************************************
	* GETTER
	*
	**********************************************************************************************/
	int getToughBirdHealth()const {
		return toughBirdHealth;
	}

	/************************************************************************************************
	* SETTER
	*
	*************************************************************************************************/
	void setToughBirdHealth(const int &toughBirdHealth);

	/*************************************************************************************************
	* DRAW
	*
	**************************************************************************************************/
	virtual void draw() 
	{
		drawToughBird(point, TOUGH_RADIUS, getToughBirdHealth()); //This text is above and beyond
		Point bonusText;
		bonusText.setX(bonusText.getX() - BONUS_X);
		bonusText.setY(bonusText.getY() + BONUS_Y);
		

		drawText(bonusText, "Bonus 5 points when destroyed"); //Bonus text +5 points
	}


	/*************************************************************************************************
	* HIT
	*
	**************************************************************************************************/
	virtual int hit() 
	{
		setToughBirdHealth(getToughBirdHealth() - HIT_BIRD);

		if (getToughBirdHealth() == 0)
		{
			kill();
			return 3;

		}
		return 1;
	}

private:
	int toughBirdHealth;

};




#endif //TOUGH_BIRD_H

