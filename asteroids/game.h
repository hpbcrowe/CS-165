/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <list>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "ship.h"

#include "rock.h"
#include "bullet.h"
#include "bigRock.h"
#include "mediumRock.h"
#include "smallRock.h"

constexpr int CLOSE_ENOUGH = 15;

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:

	Game() {} 
	/*********************************************
	 * Constructor
	 * Initializes the game
	 *********************************************/
	Game(Point tl, Point br);
	~Game();

	/*********************************************
	 * Function: handleInput
	 * Description: Takes actions according to whatever
	 *  keys the user has pressed.
	 *********************************************/
	void handleInput(const Interface & ui);

	/*********************************************
	* GET SCORE ALLOWS ACCESS TO SCORE
	*
	**********************************************/

	int getScore() const { return score; }

	/*********************************************
	* SET SCORE
	*
	***********************************************/
	void setScore(const int &score);

	/*********************************************
	 * Function: advance
	 * Description: Move everything forward one
	 *  step in time.
	 *********************************************/
	void advance();

	/*********************************************
	 * Function: draw
	 * Description: draws everything for the game.
	 *********************************************/
	void draw(const Interface & ui);

private:
	// The coordinates of the screen
	Point topLeft;
	Point bottomRight;

	Ship ship;
	std::vector<Bullet*> bullets;
	std::vector<Rock*> asteroids;
	
	/*************************************************
	 * Private methods to help with the game logic.
	 *************************************************/
	bool isOnScreen(const Point & point);
	void advanceBullets();
	void advanceRocks();
	// change to void
	void createRocks(const int & whichRock = 0,Point p = Point(), Velocity v = Velocity());
	void advanceShip();

	void handleCollisions();
	
	void cleanUpZombies();
	int score;    //Moved score to protected
	int wave;

};


#endif /* GAME_H */
