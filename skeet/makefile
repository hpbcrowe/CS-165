###############################################################
# Program:
#     Milestone 08, Skeet
#     Brother Dudley, CS165
# Author:
#     Ben Crowe
# Summary:
#     Code that allows user to shoot various clay pigeons (birds)
# Above and Beyond
#     When you submit your final project (not for milestones),
#     list anything here that you did to go above and beyond
#     the base requirements for your project.
#     I added a new bird, Wild Bird that uses random() to either 
#     add ten points to the score or subtract ten points, it 
#     uses the draw lander method. I added text and counters 
#     to the lower left hand side to show how many of each bird
#     have appeared on the screen. I added the text "Score"
#     to indentify the score.  I also added a counter to the 
#     upper left hand side to show how many shots have been fired.
#     I also added text to the sacred bird and tough bird, When
#     they appear on the screen it helps the player know the points
#     available when they shoot the bird.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o point.o bullet.o flyingObject.o bird.o sacredBird.o standardBird.o toughBird.o wildBird.o
	g++ -std=c++11 driver.o game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o point.o bullet.o flyingObject.o bird.o sacredBird.o standardBird.o toughBird.o wildBird.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
#    
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h birds.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#  velocity.o: handles movement
#  flyingObject.o: base class for all flying objects
#  bird.o: base class for birds
#  bullet.o: class for the bullet dot 
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

flyingObject.o: flyingObject.h point.h velocity.h flyingObject.cpp
	g++ -c flyingObject.cpp

bird.o: bird.h  flyingObject.h bird.cpp
	g++ -c bird.cpp

bullet.o: bullet.h flyingObject.h uiDraw.h bullet.cpp
	g++ -c bullet.cpp

sacredBird.o: sacredBird.h bird.h sacredBird.cpp
	g++ -c sacredBird.cpp

standardBird.o: standardBird.h bird.h standardBird.cpp
	g++ -c standardBird.cpp

toughBird.o: toughBird.h bird.h toughBird.cpp
	g++ -c toughBird.cpp

wildBird.o: wildBird.h bird.h wildBird.cpp
	g++ -c wildBird.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
