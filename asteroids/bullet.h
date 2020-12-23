/***********************************************************************
 * Header File:
 *    Bullet: Puts bullets flying across the screen
 * Author:
 *    Ben Crowe
 * Summary:
 *    Derived class from flyingObject which "has-a" point and a velocity
 *    draws the bullet dots and fires them across the screen
 ************************************************************************/




#ifndef bullet_h
#define bullet_h

#include "flyingObject.h"

constexpr int BULLET_SPEED = 5;  //Sets the frame speed at 5 for bullets
constexpr int BULLET_LIFE = 40;  //Sets the life of bullets for 40 frames



// Put your Bullet class here

class Bullet : public FlyingObject
{
public:

	/************************************************************************************************
	*  Constructor
	*
	************************************************************************************************/
	Bullet() : FlyingObject()
	{
		setBulletLife(BULLET_LIFE);  //Sets bullet life at 40 frames at start 
	}

	/************************************************************************************************
	* GETTER GET FORTY FRAMES
	*************************************************************************************************/
	int getBulletLife() const { return bulletLife; }  //Make private variable availble 

	/*************************************************************************************************
	* SETTER  Set the bariable for bullet life
	**************************************************************************************************/
	void setBulletLife(int bulletLife)
	{
		this->bulletLife = bulletLife;
	}

	/*************************************************************************************************
	* DRAW
	*
	**************************************************************************************************/
	virtual void draw()const 
	{
		
			drawDot(point);       //Draw bullets
		
	}

	/*************************************************************************************************
	* FIRE
	*
	**************************************************************************************************/
	void fire(const Point &point, const float &angle, const Velocity &originVelocity);

private:
	float angle; //This comes from ship
	int bulletLife;  //Variable to make bullets disappear after forty frames
};







#endif /* bullet_h */
