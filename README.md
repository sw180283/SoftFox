# SoftFox
##Comp150 Group Project
###Project Team: Sam, Thomas, Dean, Octavian

##First Trello Sprint Plan
The first sprint review is: 11/03/2016

![alt text][first_sprint_plan_group]

[first_sprint_plan_group]: https://github.com/sw180283/SoftFox/blob/master/First_Sprint_Plan_Group.jpg "First Trello Sprint Plan"

##Basic Setup
Our project is set up in Visual Studios and we are using the SDL library with C++. The first step was setting up our base programme so that the libraries and project settings were suited to this.

##Week 1 - First Pair Programming Session - Sprite render
###Task completed by: Thomas, Sam, Dean (Pair programming)
We approached this first user story as a group and worked around Thomas' laptop. This meant that we were all able to see what was needed and could each input into the code. This was useful as none of us said we were confident in C++ and it would help us to communicate as a group to do as much pair programming as possible.

The user story that we wanted to focus on was to have a basic sprite render on screen. We already had a window that opened up with a black background and a quit function that meant the player could press the red cross to close the project. The main challenge we had with this was that we had initially setup our libraries incorrectly and needed to download SDL2_image-2.0.4 to support our image load. After we did this, we were able to use a sprite to display on screen which represented the character.

##Week 2 - Second Pair Programming Session - Move character around screen, render platforms on screen, change sprite to fox
##Task completed by: Thomas, Sam (Pair programming)
In this session, we started to implement code to move the character around the screen. At the moment, the character can move in all directions, however in the final game we only require left and right movement with the jump replacing the up movement and gravity replacing the down movement.

We also were able to implement platformer rendering and started to build the design for our game. We encountered an error with our Visual Studios program, that was resolved by deleting the Debug folder. This caused frustration during this session as we were getting inconsistent errors.

Finally, we were able to change the image of the player sprite to give more idea of the intended aesthetic.

##End of first sprint
![alt text][End_of_first_sprint]

[End_of_first_sprint]: https://github.com/sw180283/SoftFox/blob/master/First_Complete_Sprint_Plan.jpg "End Of First Sprint"
