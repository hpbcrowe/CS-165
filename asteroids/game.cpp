/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

 // These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>

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

Game::Game(Point tl, Point br)
	: topLeft(tl), bottomRight(br)
{
	// Set up the initial conditions of the game
	score = 0;
	wave = 1;
		
			createRocks(0);
		
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
	// TODO: Check to see if there is currently a rock allocated
	//       and if so, delete it.
	for (int i = 0; i < asteroids.size(); i++)
	{
		delete asteroids[i];
		asteroids[i] = NULL;
	}
	for (int k = 0; k < bullets.size(); k++)
	{
		delete bullets[k];
		bullets[k] = NULL;
	}
}

/******************************************
* SET SCORE
* ALLOWS OTHER METHODS TO CHANGE SCORE
******************************************/
void Game::setScore(const int &score)
{
	this->score = score;
}


/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game::advance()
{
	advanceBullets();
	advanceRocks();
	advanceShip();

	handleCollisions();
	cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game::advanceBullets()
{
	// Move each of the bullets forward if it is alive
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->isAlive() && bullets[i] != NULL && ship.isAlive())
		{

			//Added !ship.isAlive to kill bullets when ship is killed
			if (bullets[i]->getBulletLife() == 0)
			{
				bullets[i]->kill();
			}

			bullets[i]->setBulletLife(bullets[i]->getBulletLife() - 1);
			// this bullet is alive, so tell it to move forward
			bullets[i]->advance(topLeft, bottomRight);

		}
	}
}

/**************************************************************************
 * GAME :: ADVANCE rocks
 *
 * 1. If there are no rock, create one with some probability
 * 2. If there is a rock, and it's alive, advance it
 * 3. Check if the rock has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game::advanceRocks()
{
	for (int i = 0; i < asteroids.size(); i++)
	{
		if (asteroids[i]->isAlive() && asteroids[i] != NULL)
		{

			// this asteroid is alive, so tell it to move forward
			asteroids[i]->advance(topLeft, bottomRight);

			if (!isOnScreen(asteroids[i]->getPoint())) {
				// the asteroid has left the screen
				asteroids[i]->kill();
			}

		}
	}

}

/**************************************************************************
*  GAME :: ADVANCE SHIP
*  Move the ship across the screen
***************************************************************************/
void Game::advanceShip()
{
	if (ship.isAlive())
	{
		ship.advance(topLeft, bottomRight);
	}
	else
	{
		if (!ship.isAlive())
			Ship();
	}

}


/**************************************************************************
 * GAME :: CREATE rocks
 * Create a LARGE ASTEROID at a random point of the game.
 **************************************************************************/
void Game::createRocks(const int & whichRock, Point p, Velocity v)
{

	// point
	// velocity
	Point point;
    Velocity velocity;
	
	switch (whichRock)
	{
	case 1:
	{
		// do what happends when a big rock gets hit
		//1st Medium Rock
		Rock* newrock6 = NULL;

		velocity.setDy(v.getDy() + 1);   //Adam's help


		newrock6 = new MediumRock(p, velocity);
		asteroids.push_back(newrock6);

		//2nd Medium Rock
		Rock* newrock5 = NULL;

		velocity.setDy(v.getDy() - 4);     //Adam helped me


		newrock6 = new MediumRock(p, velocity);
		asteroids.push_back(newrock6);

		//Small Rock
		Rock* newrock7 = NULL;

		velocity.setDx(v.getDx() + 2);    //This is with Adam's help

		newrock7 = new SmallRock(p, velocity);
		asteroids.push_back(newrock7);

	}
	break;
	case 2:
	{
		//What happens when a medium rock gets hit

		//1st small rock
		Rock* newrock8 = NULL;

		velocity.setDx(v.getDx() + 3);    //This is with Adam's help

		newrock8 = new SmallRock(p, velocity);
		asteroids.push_back(newrock8);

		//Second small rock
		Rock* newrock9 = NULL;

		velocity.setDx(v.getDx() - 6);    //This is with Adam's help

		newrock9 = new SmallRock(p, velocity);
		asteroids.push_back(newrock9);
	}

	break;

	case 3:
		//What happens when a small rock gets hit
		//nothing
		break;
	default:
	{
		
		int spin = random(0, 10);
						
		//1st Big Rocks
		Rock* newrock1 = NULL;

		velocity.setDy(1.0);   //Adam's help
		velocity.setDx(1.0);
		point.setX(random(-200, 0));
		point.setY(random(0, 200));
		//int spin = random(0, 5000);
		
		newrock1 = new BigRock(point, velocity, spin);
		asteroids.push_back(newrock1);
		//2ND BIG ROCK
		Rock* newrock2 = NULL;

		velocity.setDy(-4.0);   //Adam's help
		velocity.setDx(-2.0);
		point.setX(random(-200, 0));
		point.setY(random(-50, 50));
		//int spin = random(0, 5000);
				
		newrock2 = new BigRock(point, velocity, spin);
		asteroids.push_back(newrock2);

		//3RD BIG ROCK
		Rock* newrock3 = NULL;

		velocity.setDy(1.0);   //Adam's help
		velocity.setDx(1.0);
		point.setX(random(-200, 0));
		point.setY(random(-200, 0));
		//int spin = random(0, 5000);
		
		newrock3 = new BigRock(point, velocity, spin);
		asteroids.push_back(newrock3);

		//4TH BIG ROCK
		Rock* newrock4 = NULL;

		velocity.setDy(-1.0);   //Adam's help
		velocity.setDx(1.0);
		point.setX(random(0, 200));
		point.setY(random(50, 200));
		//int spin = random(0, 5000);

		newrock4 = new BigRock(point, velocity, spin);
		asteroids.push_back(newrock4);

		//5TH BIG ROCK
		Rock* newrock5 = NULL;

		velocity.setDy(1.0);   //Adam's help
		velocity.setDx(1.0);
		point.setX(random(0, 200));
		point.setY(random(-200, 0));
		//int spin = random(0, 5000);

		newrock5 = new BigRock(point, velocity, spin);
		asteroids.push_back(newrock5);
	}
	break;
	}
	
}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game::isOnScreen(const Point & point)
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
void Game::handleCollisions()
{
	// now check for a hit (if it is close enough to any live bullets)
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->isAlive())
		{
			// this bullet is alive, see if its too close
			for (int j = 0; j < asteroids.size(); j++)
			{


				// check if the asteroid is at this point (in case it was hit)
				if (asteroids[j] != NULL && asteroids[j]->isAlive())
				{
					// BTW, this logic could be more sophisiticated, but this will
					// get the job done for now...
					if (fabs(bullets[i]->getPoint().getX() - asteroids[j]->getPoint().getX()) < CLOSE_ENOUGH
						&& fabs(bullets[i]->getPoint().getY() - asteroids[j]->getPoint().getY()) < CLOSE_ENOUGH && bullets[i]->isAlive())
						//Had to add check to see if bullet is alive
					{
						//we have a hit!

						// hit the asteroid
						int whichRock = asteroids[j]->hit();
						int points = asteroids[j]->scorePoints();
						score += points;

						createRocks(whichRock, asteroids[j]->getPoint(), asteroids[j]->getVelocity());

						// the bullet is dead as well
						bullets[i]->kill();
						
					}
				}
			}

		} // if bullet is alive

	} 

	   //ship/asteroid collision 
	if (asteroids.size() < 1)
	{
		
			createRocks(0);
			wave++;
			score += 100;
	}

	for (int k = 0; k < asteroids.size(); k++)
	{
		if (asteroids[k] != NULL && asteroids[k]->isAlive())
		{
			// this asteroid is alive, see if its too close

			// check if the ship is at this point (in case it was hit)
			if (ship.isAlive())
			{
				// BTW, this logic could be more sophisiticated, but this will
				//try putting ship first and subtracting asteroids
				// get the job done for now...
				if (fabs(ship.getPoint().getX() - asteroids[k]->getPoint().getX()) < CLOSE_ENOUGH
					&& fabs(ship.getPoint().getY() - asteroids[k]->getPoint().getY()) < CLOSE_ENOUGH)
				{
					//we have a hit!

					ship.setShipLife(ship.getShipLife() - 1);
					
						ship.hit();
						//int extraLife = asteroids[k]->freeLife();
					
				}

			}
		} // if bullet is alive
	}
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate bird)
 **************************************************************************/
void Game::cleanUpZombies()
{
	// check for dead asteroids
	vector<Rock*>::iterator rockIt = asteroids.begin();

	while (rockIt != asteroids.end())
	{
		Rock * pRock = *rockIt;
		if (!(pRock->isAlive()))
		{
			delete pRock;
			pRock = NULL;

			// remove from list and advance
			rockIt = asteroids.erase(rockIt);
		}
		else
		{
			rockIt++; // advance
		}
	}

	// Look for dead bullets
	vector<Bullet*>::iterator bulletIt = bullets.begin();
	while (bulletIt != bullets.end())
	{
		Bullet * pBullet = *bulletIt;
		// Asteroids Hint:
		// If we had a list of pointers, we would need this line instead:
		//Bullet* pBullet = *bulletIt;

		if (!pBullet->isAlive())
		{
			// If we had a list of pointers, we would need to delete the memory here...
			delete pBullet;
			pBullet = NULL;

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
void Game::handleInput(const Interface & ui)
{
	// Rotate the ship
	if (ui.isLeft())
	{
		ship.rotateLeft();
	}

	if (ui.isRight())
	{
		ship.rotateRight();
	}
	//Apply thrust from the bottom
	if (ui.isUp())
	{
		ship.applyThrustBottom();
		ship.setThrust(true);   //Set thrust to true to draw flame
	}
	else
		ship.setThrust(false);  //If up isn't pushed set thrust to false and 
								//don't draw flame

	// Check for "Spacebar
	if (ui.isSpace())
	{

		if (ship.isAlive())
		{
			
			Bullet * newBullet = new Bullet();    //Fire bullets when spacebar is pushed
			newBullet->fire(ship.getPoint(), ship.getAngle(), ship.getVelocity()); //passing ships vel,point and
																				   //angle
			bullets.push_back(newBullet);
		}
	}
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game::draw(const Interface & ui)
{
	

	//Draw rocks if they are alive

	for (int i = 0; i < asteroids.size(); i++)
	{
		if (asteroids[i] != NULL && asteroids[i]->isAlive())
		{
			asteroids[i]->draw();
		}

	}

	
	// draw the ship
	if (ship.isAlive())
	{
		ship.draw();
	}
	else
		if (!ship.isAlive())
		{
			Point gameOverText;
			//Put the text "Game Over" on screen            //This text is above and beyond
			gameOverText.setX(-45);
			gameOverText.setY(0);
			drawText(gameOverText, "GAME OVER");
		}

	// draw the bullets, if they are alive
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->isAlive() && bullets[i] != NULL && ship.isAlive())
		{
			bullets[i]->draw();

		}

	}
	

	//Put the score on the screen
	Point scoreLocation;
	Point textLocation;
	scoreLocation.setX(topLeft.getX() + 550);
	scoreLocation.setY(topLeft.getY() - 16);
	//Put the text "Score" on screen            //This text is above and beyond
	textLocation.setX(topLeft.getX() + 500);
	textLocation.setY(topLeft.getY() - 25);
	drawText(textLocation, "SCORE:");
	drawNumber(scoreLocation, score);
	                                              //All of this below is above and beyond
	//This is to display amount of liFes left
	Point lifeCountLocation((topLeft.getX() + 25), topLeft.getY() - 25); //This is with Daniel's help

	vector <Point> lifeShips;
	for (int i = 0, xValue = 80, yValue = 20; i < 3; i++)
	{
		lifeShips.push_back(Point((topLeft.getX() + xValue), (topLeft.getY() - yValue)));
		xValue += 15;
	}
	
	
	
	drawText(lifeCountLocation, "LIVES :");
	for (int i = 0; i < ship.getShipLife(); i++)
	{
		drawShip(lifeShips[i], 0, false);
	}
	//Put the Wave on the screen, how many times screen has been cleared
	Point waveLocation;
	Point waveTextLocation;
	waveLocation.setX(topLeft.getX() + 550);
	waveLocation.setY(topLeft.getY() - 36);
	//Put the text "WAVE" on screen            //This text is above and beyond
	waveTextLocation.setX(topLeft.getX() + 500);
	waveTextLocation.setY(topLeft.getY() - 45);
	drawText(waveTextLocation, "WAVE:");
	drawNumber(waveLocation, wave);

}



// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
 /*
 float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
 {
	// find the maximum distance traveled
	float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
	dMax = max(dMax, abs(obj2.getVelocity().getDx()));
	dMax = max(dMax, abs(obj2.getVelocity().getDy()));
	dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.

	float distMin = std::numeric_limits<float>::max();
	for (float i = 0.0; i <= dMax; i++)
	{
	   Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
					  obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
	   Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
					  obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));

	   float xDiff = point1.getX() - point2.getX();
	   float yDiff = point1.getY() - point2.getY();

	   float distSquared = (xDiff * xDiff) +(yDiff * yDiff);

	   distMin = min(distMin, distSquared);
	}

	return sqrt(distMin);
 }
 */