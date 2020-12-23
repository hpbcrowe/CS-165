/***************************************************************************************************
* File: bullet.h
* Author: Ben Crowe
* Description:
*   class for the bullet , dot that shoots out of the rifle
*
****************************************************************************************************/

#ifndef BULLET_H
#define BULLET_H

#include "flyingObject.h"  //To pull in velocity and Point class 


#include <cmath>   //used for sin, cos, and M_PI

const int BULLET_SPEED = 10.0;
const int PI = 3.144;
const int STRAIGHT_LINE = 180;

class Bullet : public FlyingObject
{
public:

	/************************************************************************************************
	*  Constructor
	*
	************************************************************************************************/
	Bullet() {}
	
	/*************************************************************************************************
	* DRAW
	*
	**************************************************************************************************/
	void draw();

	/*************************************************************************************************
	* FIRE
	*
	**************************************************************************************************/
	void fire(const Point &point,const float &angle);

private:
	float angle; //This comes from rifle
};




#endif //BULLET_H

