
/*********************************************************************************
*  HEADER FILE:
*      VELOCITY:
*  Author:
*   Ben Crowe
*  Summary:
*  This class supplies the variables and methods so that motion appears on the
*   screen. Point x,y is the beginning point and velocity dX dY is the next point
**********************************************************************************/




#ifndef VELOCITY_H
#define VELOCITY_H



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


#endif // !VELOCITY.H
