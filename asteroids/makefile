###############################################################
# Program:
#     Project 13, Asteroids
#     Brother Dudley, CS165
# Author:
#     Ben Crowe
# Summary:
#     Asteroids game 
# Above and Beyond
#     -To get rid of magic numbers used constexp int and float.
#     -Added code to have each rock return a score and displayed
#     score.
#     -Added code have the ship start out with 3 lives then added
#     a vector that held the points on the screen where the lifes
#     were displayed. Added the code so that lives are displayed
#     with a ship icon instead of a number.
#     -Added code so that game doesn't end when all of the 
#     asteroids are destroyed a new wave of asteroids will begin
#     -Added code to have each asteroid rotate clockwise and 
#      counterclockwise doesn't always work
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rock.o bigRock.o mediumRock.o smallRock.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rock.o bigRock.o mediumRock.o smallRock.o  $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObject.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rock.o        Contains all of the Rock classes
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -std=c++11 -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -std=c++11 -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -std=c++11 -c point.cpp

driver.o: driver.cpp game.h
	g++ -std=c++11 -c driver.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h flyingObject.h bullet.h rock.h bigRock.h mediumRock.h smallRock.h ship.h
	g++ -std=c++11 -c game.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -std=c++11 -c velocity.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -std=c++11 -c flyingObject.cpp

ship.o: ship.cpp ship.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -std=c++11 -c ship.cpp

bullet.o: bullet.cpp bullet.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -std=c++11 -c bullet.cpp

rock.o: rock.cpp rock.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -std=c++11 -c rock.cpp

bigRock.o: bigRock.cpp rock.h bigRock.h 
	g++ -std=c++11 -c bigRock.cpp

mediumRock.o: mediumRock.cpp rock.h mediumRock.h
	g++ -std=c++11 -c mediumrock.cpp

smallRock.o: smallRock.cpp rock.h smallRock.h
	g++ -std=c++11 -c smallRock.cpp



###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
