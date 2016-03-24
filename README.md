# SoftFox
##Comp150 Group Project
###Project Team: Sam, Thomas, Dean, Octavian

[First Time Downloading Folder](#first-time-downloading-folder)  
[First Trello Sprint Plan](#first-trello-sprint-plan)  
[Week 1](#week-1---first-pair-programming-session---sprite-render)  
[Week 2](#week-2---second-pair-programming-session---move-character-around-screen,-render-platforms-on-screen,-change-sprite-to-fox)  
[The First Sprint Review](#the-first-sprint-review)  
[Start Of Second Sprint](#start-of-second-sprint)  

#First Time Downloading Folder
The first time you download this to your computer, there is no Debug folder. So when you first start go to SoftFox-SoftFox-SoftFox.sln, then make sure the Solutions Configuration is set to Debug Solution Platforms is set to x84 and run Local Windows Debugger. After you cancel the error. Go to the project folder SDL2-2.0.4-lib-x84 and copy the SDL2.dll file and paste it into Debug folder found in the same location as the SDL2-2.0.4 folder. Then go to SDL2_image-2.0.1-lib-x84 and copy all 6 .dll files and paste them in the same Debug folder. Now, the prject should run fine.

##First Trello Sprint Plan
The first sprint review is: 11/03/2016

![alt text][first_sprint_plan_group]

[first_sprint_plan_group]: https://github.com/sw180283/SoftFox/blob/master/Trello/First_Sprint_Plan_Group.jpg "First Trello Sprint Plan"

##Trello Board Name Labels

![alt text][trello_board_name_label]

[trello_board_name_label]: https://github.com/sw180283/SoftFox/blob/master/Trello/Trello_Board_Name_Labels.jpg "Trello Board Name Labels"

##Basic Setup
Our project is set up in Visual Studios and we are using the SDL library with C++. The first step was setting up our base programme so that the libraries and project settings were suited to this.

##Week 1 - First Pair Programming Session - Sprite render
###Task completed by: Thomas, Sam, Dean (Pair programming)
We approached this first user story as a group and worked around Thomas' laptop. This meant that we were all able to see what was needed and could each input into the code. This was useful as none of us said we were confident in C++ and it would help us to communicate as a group to do as much pair programming as possible.

The user story that we wanted to focus on was to have a basic sprite render on screen. We already had a window that opened up with a black background and a quit function that meant the player could press the red cross to close the project. The main challenge we had with this was that we had initially setup our libraries incorrectly and needed to download SDL2_image-2.0.4 to support our image load. After we did this, we were able to use a sprite to display on screen which represented the character.

##Week 2 - Second Pair Programming Session - Move character around screen, render platforms on screen, change sprite to fox
###Task completed by: Thomas, Sam (Pair programming)
In this session, we started to implement code to move the character around the screen. At the moment, the character can move in all directions, however in the final game we only require left and right movement with the jump replacing the up movement and gravity replacing the down movement.

We also were able to implement platformer rendering and started to build the design for our game. We encountered an error with our Visual Studios program, that was resolved by deleting the Debug folder. This caused frustration during this session as we were getting inconsistent errors.

Finally, we were able to change the image of the player sprite to give more idea of the intended aesthetic.

##End of first sprint
![alt text][End_of_first_sprint]

[End_of_first_sprint]: https://github.com/sw180283/SoftFox/blob/master/Trello/First_Complete_Sprint_Plan.jpg "End Of First Sprint"

##The First Sprint Review
There was some issues raised with our layout of our trello board, such as using labels to respresent our members. It was suggested by our "Product manager" to use the members functions of Trello and instead use the labels for a way to represent the tasks. Therefore, we have created labels for: programming, design, art and research.

Another suggestion was to prioritise our trello backlog with the user stories are most needed for our game to be at the top. We have found this to be useful in seeing which areas of our project we need to approach next.

We were also recommened to start our self, group and peer evaulation in private documents to document our progress. A suggested method was Post-mortum which looks at some achievements which we were proud of, and some areas of improvement.

The overall, we feel this sprint went well as we achieved all but one of our intended user stories. For improvement, Github branches could have been used more to make sure we always have a working master with separate branches to have work in progress user stories.

##Start Of Second Sprint
![alt text][Start_of_second_sprint] 

[Start_of_second_sprint]: https://github.com/sw180283/SoftFox/blob/master/Trello/Second_Group_Sprint_Plan.jpg "Start Of Second Sprint"

##Week 3 - Code Clean Up Branches
In this week, we attempted to use branches to improve our agile practises, in addition to communication about code issues. We have been using Facebook and Slack to coomunicate some of this issues however Github pull request allows us to see differences in code and comment on individual lines.

After we all looked through the first branch, and knew what every line of code did and commented it, we merged this branch with the main. There were some issues to start with as there were some merge conflicts, or syncs wouldn't exit on Github desktop however these were resolved when we deleted some unnecessary folders and files and added them to the gitignore. Now our project downloads faster and it is better for seeing where the code has changed.

##Week 4 - Research Into Similar Games
As we have a lot of work this week, we decided to focus our project on researching how other games have approached a similiar target audience. This is required as part of our commersial awareness but it gave us some ideas on how to approach level layout and game introduction.

An issue for this week was that we didn't allocate enough time to coding our project so it hasn't changed much from last week. Also, more commits are recommended to improve professional practise.
