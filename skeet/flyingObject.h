/***************************************************************************************************
* File: flyingObject.h
* Author: Ben Crowe
* Description:
*   This is the base class for bird.h, standardBird.h, toughBird.h, sacredBird.h and bullet.h
*
****************************************************************************************************/

#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H 

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class FlyingObject
{
public:
/************************************************************************************************
*  Constructor
*
************************************************************************************************/
	FlyingObject() : alive(true) {}

/***********************************************************************************************
* GETTERS
*
************************************************************************************************/
	Point getPoint() const { return point; }  //To create a position for flying objects
	Velocity getVelocity() const { return velocity; } //To create movement for flying objects
	bool isAlive() const { return alive; } //Birds and bullets will start out alive.


/************************************************************************************************
* SETTERS
*
*************************************************************************************************/
	void setPoint(const Point &point);  //mutate point
	void setVelocity(const Velocity &velocity); //Mutate velocity

/*************************************************************************************************
*  KILL
*
**************************************************************************************************/
	void kill();

/*************************************************************************************************
* ADVANCE
*
**************************************************************************************************/
	void advance();

/*************************************************************************************************
* DRAW
*
**************************************************************************************************/
	virtual void draw() = 0;


	

protected:
	Point point;
	Velocity velocity;
	bool alive;
	
	

};




#endif //FLYINGOBJECT_H 
