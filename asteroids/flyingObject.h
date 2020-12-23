/***********************************************************************
 * Header File:
 *    Flying Object : Base class for all of the objects that "fly" across
      screen
 * Author:
 *    Ben Crowe
 * Summary:
 *    This is the code necessary to put flying objects on screen
 *     it accepts a point and a velocity, it is the base class for bullet
 *     ship and rocks
 ************************************************************************/

#ifndef flyingObject_h
#define flyingObject_h

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

namespace rockData
{
	constexpr int BIG_Rock_SIZE = 16;
	constexpr int MEDIUM_Rock_SIZE = 8;
	constexpr int SMALL_Rock_SIZE = 4;
}

class FlyingObject
{
public:
	/************************************************************************************************
	*  Constructor
	*
	************************************************************************************************/
	FlyingObject() : alive(true)  {}

	/***********************************************************************************************
	* GETTERS
	*
	************************************************************************************************/
	Point getPoint() const { return point; }  //To create a position for flying objects
	Velocity getVelocity() const { return velocity; } //To create movement for flying objects
	bool isAlive() const { return alive; } //Asteroids and bullets will start out alive.


/************************************************************************************************
* SETTERS
*
*************************************************************************************************/
	void setPoint(const Point &point);  //mutate point
	void setVelocity(const Velocity &velocity); //Mutate velocity
	void setAlive(const bool &alive);

/*************************************************************************************************
*  KILL
*
**************************************************************************************************/
	void kill();

	/*************************************************************************************************
	* ADVANCE
	*
	**************************************************************************************************/
	void advance(Point topLeft, Point bottomRight);  //This moves flying objects, passing topLeft and
	                                                 //bottomRight points for screen wrapping 
	/*************************************************************************************************
	* DRAW
	*
	**************************************************************************************************/
	virtual void draw() const = 0;

protected:
	Point point;          //Poistion of flying object
	Velocity velocity;    //Movement of flying object, next position
	bool alive;           //Variable to decide if something is alive or dead
};

#endif /* flyingObject_h */
