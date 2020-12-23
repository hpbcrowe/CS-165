/***********************************************************************
 * Header File:
 *    Ship : The representation of the ship on the screen
 * Author:
 *   Ben Crowe
 * Summary:
 *  Everything for the ship on the screen  
 *
 ************************************************************************/

#ifndef ship_h
#define ship_h

constexpr int SHIP_SIZE = 10;
constexpr int INITIAL_LIFE = 3;

constexpr int ROTATE_AMOUNT = 15;  //Changed rotate amount
#define THRUST_AMOUNT  0.5       //Wouldn't work as a constexpr int
constexpr int SHIP_Y = 50;     //Initial starting position
constexpr float speed_limit = 6.0;



// Put your Ship class here
#include "flyingObject.h"




class Ship : public FlyingObject
{
public:
	/********************************************************************************
	* CONSTRUCTORS
	*
	*********************************************************************************/
	Ship();

	
	/*********************************************************************************
	* GETTERS
	**********************************************************************************/
	
	bool getThrust() const { return thrust; }
	bool canThrust() const { return thrust; }
	float getAngle() const { return angle; }
	int getShipLife() const { return shipLife; }

	/**********************************************************************************
	* SETTERS
	***********************************************************************************/
	void setThrust(const bool &thrust);
	void setShipLife(const int &shipLife);
	

	/**********************************************************************************
	* ROTATE  LEFT
	* ROTATES SHIP TO THE LEFT
	***********************************************************************************/
	void rotateLeft();

	/**********************************************************************************
	* ROTATE RIGHT
	* ROTATES SHIP TO THE RIGHT
	***********************************************************************************/
	void rotateRight();

	/**********************************************************************************
	* APPLY THRUST BOTTOM
	* CHANGES THE MOMENTUM  WHEN THIS IS APPLIED
	***********************************************************************************/
	void applyThrustBottom();

	/**********************************************************************************
	* DRAW
	*
	***********************************************************************************/
	virtual void draw() const
{
		    				                      //PASSES the ships point, 90-angle for the direction bullets
	                                             //will come out of and the thrust bool to determine when to 
												  //draw flames
	drawShip(point, 90 - angle, thrust);
						                                         
}                                                 
	                                             

	/***********************************************************************************
	* HIT
	*
	***********************************************************************************/
	void hit();

private:
	
    bool thrust;
	bool alive;
	float angle;
	int shipLife;



	/**********************************************************************************
	* DESTRUCTOR
	************************************************************************************/

};


#endif /* ship_h */
