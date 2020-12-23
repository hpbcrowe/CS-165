###############################################################
# Program:
#     Milestone 06, Moon Lander
#     Brother Dudley, CS165
# Author:
#     Ben Crowe
# Summary:
#     Put your summary code here... 
# Above and Beyond
#     When you submit your final project (not for milestones),
#     list anything here that you did to go above and beyond
#     the base requirements for your project.
#     In Lander.cpp on line 24 I changed the initial position 
#     of the lander so that it wouldn't appear in a mountain
#     In Driver.cpp on lines 38 and 39 I changed the size of 
#     the screen to 300,-300 so that the screen would be easier
#     to see. I attemped to do screen wrapping in game.cpp
#     on lines 83-96 but I couldn't get it to work. Daniel 
#     helped me tweek these.
#     In game.cpp on line 144 I added the text "Game Over"
#     when the lander crashes. I also adjusted where the 
#     "you successfully landed" appears so it wasn't in the 
#      mountains and I added "Congratulations" above it 
#     lines 137 and 139.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o
	g++ driver.o ground.o game.o uiInteract.o uiDraw.o point.o velocity.o lander.o $(LFLAGS)
	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
#    lander.o      Handles the direction of the object
#    velocity.o    Movement of the object 
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h point.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h
	g++ -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h lander.h 
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ -c driver.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
velocity.o: velocity.h velocity.cpp 
	g++ -c velocity.cpp

lander.o: lander.h lander.cpp uiDraw.h velocity.h point.h
	g++ -c lander.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
