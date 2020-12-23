/***********************************************************************
 * Header File:
 *    Velocity : Makes objects move
 * Author:
 *    Ben Crowe
 * Summary:
 *     This makes objects move across the screen.   
 *
 ************************************************************************/



#ifndef VELOCITY_H
#define VELOCITY_H


// Put your velocity class here, or overwrite this file with your own
// velocity class from the previous project


class Velocity
{
public:
	/********************************************************************************
	* CONSTRUCTORS
	*
	********************************************************************************/

	Velocity();

	Velocity(const float & Dx, const float &Dy);


	/********************************************************************************
	* GETTERS
	*********************************************************************************/
	float getDx() const { return dx; }
	float getDy() const { return dy; }

	/********************************************************************************
	* SETTERS
	*********************************************************************************/
	void setDx(const float &dx);
	void setDy(const float &dy);


private:
	float dx;
	float dy;


};

#endif /* velocity_h */
