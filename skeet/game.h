/*************************************************************
 * File: game.h
 * Author: Br. Burton
 *
 * Description: The game of Skeet. This class holds each piece
 *  of the game (birds, bullets, rifle, score). It also has
 *  methods that make the game happen (advance, interact, etc.)
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "rifle.h"

// TODO: include your bullet and bird classes
#include "bird.h"
#include "bullet.h"
#include "standardBird.h"
#include "toughBird.h"
#include "sacredBird.h"
#include "wildBird.h"


#define CLOSE_ENOUGH 15


/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:

	Game();
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

   int bulletCount;         //All of these variables are above and beyond
   int standardBirdCount;
   int sacredBirdCount;
   int toughBirdCount;
   int wildBirdCount;
   int accuracy;
   int dice;
   
   
   
   Rifle rifle;
   std::vector<Bullet> bullets;
   
   // TODO: declare your bird here (e.g., "Bird * bird;")
   Bird *bird;
   



   /*************************************************
    * Private methods to help with the game logic.
    *************************************************/
   bool isOnScreen(const Point & point);
   void advanceBullets();
   void advanceBird();
   Bird* createBird();
   
   void handleCollisions();
   void cleanUpZombies();

protected:
	int score;    //Moved score to protected

};

#endif /* GAME_H */
