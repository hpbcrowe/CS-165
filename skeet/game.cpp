/*************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"

#include <vector>
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5


/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br), rifle(br)
{
   // Set up the initial conditions of the game
   score = 0;

   // TODO: Set your bird pointer to a good initial value (e.g., NULL)
   bird = NULL;   //This is also with Daniel's help
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   // TODO: Check to see if there is currently a bird allocated
   //       and if so, delete it.
	if (bird != NULL)
		delete bird;  //This is with Daniel's help
	bird = NULL;

}

/******************************************
* SET SCORE
* ALLOWS OTHER METHODS TO CHANGE SCORE
******************************************/
void Game ::setScore(const int &score)
{
	this->score = score;
}


/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   advanceBullets();
   advanceBird();

   handleCollisions();
   cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
{
   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i].advance();
         
         if (!isOnScreen(bullets[i].getPoint()))
         {
            // the bullet has left the screen
            bullets[i].kill();
         }
         
      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE BIRD
 *
 * 1. If there is no bird, create one with some probability
 * 2. If there is a bird, and it's alive, advance it
 * 3. Check if the bird has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game :: advanceBird()
{
   if (bird == NULL)
   {
      // there is no bird right now, possibly create one
      
      // "resurrect" it will some random chance
      if (random(0, 30) == 0)
      {
         // create a new bird
         bird = createBird();
      }
   }
   else
   {
      // we have a bird, make sure it's alive
      if (bird->isAlive())
      {
         // move it forward
         bird->advance();
         
         // check if the bird has gone off the screen
         if (!isOnScreen(bird->getPoint()))
         {
            // We have missed the bird
            bird->kill();
         }
      }
   }
   
}

/**************************************************************************
 * GAME :: CREATE BIRD
 * Create a bird of a random type according to the rules of the game.
 **************************************************************************/
Bird* Game :: createBird()
{
   Bird* newBird = NULL;

   int selectBird = random(1, 6);

   // TODO: Fill this in
   Point origin;
   Velocity startDirection;
   origin.setX(topLeft.getX()); //Left hand side, this is w/ Daniels help
   origin.setY(random(topLeft.getX(), topLeft.getY()));
   
	   
 
   
   //Do switch here with different bird types that pass origin into
   switch (selectBird)
   {
   case 1:
	   newBird = new StandardBird(origin);	 //Daniel helped me with this switch
	   standardBirdCount++;
	   break;                               //to randomly generate birds
   case 2:
	   newBird = new ToughBird(origin);
	   toughBirdCount++;
	   break;
   case 3:
	   newBird = new SacredBird(origin);
	   sacredBirdCount++;
	   break;
   case 4:
	   newBird = new WildBird(origin);
	   wildBirdCount++;
	   /*if (bird->hit())
	   {
		   int dice = random(1, 3);  //Trying to double or cut score in half
		   if (dice == 2)
		   {
			   score = score * 2;
		   }
		   else
			   score = score / 2;
	   }*/
	   		   
	   break;

   }
   
   
   return newBird;
}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game :: isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a bird and a bullet.
 **************************************************************************/
void Game :: handleCollisions()
{
   // now check for a hit (if it is close enough to any live bullets)
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, see if its too close

         // check if the bird is at this point (in case it was hit)
         if (bird != NULL && bird->isAlive())
         {
            // BTW, this logic could be more sophisiticated, but this will
            // get the job done for now...
            if (fabs(bullets[i].getPoint().getX() - bird->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - bird->getPoint().getY()) < CLOSE_ENOUGH)
            {
               //we have a hit!
               
               // hit the bird
               int points = bird->hit();
               score += points;
               
               // the bullet is dead as well
               bullets[i].kill();
            }
         }
      } // if bullet is alive
      
   } // for bullets
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate bird)
 **************************************************************************/
void Game :: cleanUpZombies()
{
   // check for dead bird
   if (bird != NULL && !bird->isAlive())
   {
      // the bird is dead, but the memory is not freed up yet
      
      // TODO: Clean up the memory used by the bird
	   delete bird;
	   bird = NULL;
   
   }
   
   // Look for dead bullets
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;
      // Asteroids Hint:
      // If we had a list of pointers, we would need this line instead:
      //Bullet* pBullet = *bulletIt;
      
      if (!bullet.isAlive())
      {
         // If we had a list of pointers, we would need to delete the memory here...
         
         
         // remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }
   
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // Change the direction of the rifle
   if (ui.isLeft())
   {
      rifle.moveLeft();
   }
   
   if (ui.isRight())
   {
      rifle.moveRight();
   }
   
   // Check for "Spacebar
   if (ui.isSpace())
   {
	   bulletCount++;   //Count amount of bullets fired to equate accuracy.
	   accuracy = score / bulletCount;
	   
      Bullet newBullet;
      newBullet.fire(rifle.getPoint(), rifle.getAngle());
      
      bullets.push_back(newBullet);
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{

   // draw the bird
	

   // TODO: Check if you have a valid bird and if it's alive

   // then call it's draw method
	if (bird != NULL && bird->isAlive())
		bird->draw();
	
  

   // draw the rifle
   rifle.draw();
   
   // draw the bullets, if they are alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         bullets[i].draw(); 
		                       
      }
	 
   }
   
   // Put the score on the screen
   Point scoreLocation;
   Point textLocation;
   scoreLocation.setX(topLeft.getX() + 45);
   scoreLocation.setY(topLeft.getY() - 5);
   //Put the text "Score" on screen            //This text is above and beyond
   textLocation.setX(topLeft.getX() + 5);
   textLocation.setY(topLeft.getY() - 15);
   drawText(textLocation, "Score:");
   
   drawNumber(scoreLocation, score);          //All of this below is above and beyond
   //Testing for future accuracy score
   Point bulletCountLocation;
   Point shotsFiredTextLocation;
   
   shotsFiredTextLocation.setX(topLeft.getX() + 75);
   shotsFiredTextLocation.setY(topLeft.getY() - 15);
   bulletCountLocation.setX(topLeft.getX() + 155);
   bulletCountLocation.setY(topLeft.getY() - 5);
   drawNumber(bulletCountLocation, bulletCount);
   drawText(shotsFiredTextLocation, "Shots Fired:");

   //Put count of how many birds have appeared on screen

	//Wild Bird Count Location
   Point wildBirdCountLocation;
   Point wildBirdText;
   wildBirdCountLocation.setX(topLeft.getX() + 115);
   wildBirdCountLocation.setY(topLeft.getY() - 295);
   wildBirdText.setX(topLeft.getX() + 5);
   wildBirdText.setY(topLeft.getY() - 305);
   drawNumber(wildBirdCountLocation, wildBirdCount);
   drawText(wildBirdText, "Wild Bird Count:");

   //Sacred Bird Count Location
   Point sacredBirdCountLocation;
   Point sacredBirdText;
   
   sacredBirdCountLocation.setX(topLeft.getX() + 115);
   sacredBirdCountLocation.setY(topLeft.getY() -320);
   sacredBirdText.setX(topLeft.getX() + 5);
   sacredBirdText.setY(topLeft.getY() -330);
   drawNumber(sacredBirdCountLocation, sacredBirdCount);
   drawText(sacredBirdText, "Sacred Bird Count:");

   //Tough Bird Count Location
   Point toughBirdCountLocation;
   Point toughBirdText;
   toughBirdCountLocation.setX(topLeft.getX() + 115);
   toughBirdCountLocation.setY(topLeft.getY() - 345);
   toughBirdText.setX(topLeft.getX() + 5);
   toughBirdText.setY(topLeft.getY() - 355);
   drawNumber(toughBirdCountLocation, toughBirdCount);
   drawText(toughBirdText, "Tough Bird Count:");


   //Standard Bird Count Location
   Point standardBirdCountLocation;
   Point standardBirdText;
   standardBirdCountLocation.setX(topLeft.getX() + 115);
   standardBirdCountLocation.setY(topLeft.getY() - 370);
   standardBirdText.setX(topLeft.getX() + 5);
   standardBirdText.setY(topLeft.getY() - 380);
   drawNumber(standardBirdCountLocation, standardBirdCount);
   drawText(standardBirdText, "Stndrd Bird Count:");

   
   
}
