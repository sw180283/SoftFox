# SoftFox
##Comp150 Group Project
###Project Team: Sam, Thomas, Dean, Octavian

[First Time Downloading Folder](#first-time-downloading-folder)  
[First Trello Sprint Plan](#first-trello-sprint-plan)  
[Week 1](#week-1---first-pair-programming-session---sprite-render)  
[Week 2](#week-2---second-pair-programming-session---move-character-around-screen,-render-platforms-on-screen,-change-sprite-to-fox)  
[The First Sprint Review](#the-first-sprint-review)  
[Start Of Second Sprint](#start-of-second-sprint)  
[Week 3](#week-3---code-clean-up-branches)  
[Week 4](#week-4---research-into-similar-games)  
[The Second Sprint Review](#the-second-sprint-review)  
[Week 5-7](#week-5-7---notepad-map-design-implementation)  
[Week 8](#week-8---tiled-level-layout-implemented)  
[Week 9](#week-9---platform-dirt-uses-level)  
[The Third Sprint Review](#the-third-sprint-review)
[Week 10](#week-10---working-on-our-own-elements-to-the-game)    

#First Time Downloading Folder
The first time you download this to your computer, there is no Debug folder. So when you first start go to SoftFox-SoftFox-SoftFox.sln, then make sure the Solutions Configuration is set to Debug Solution Platforms is set to x84 and run Local Windows Debugger. After you cancel the error. Go to the project folder SDL2-2.0.4-lib-x84 and copy the SDL2.dll file and paste it into Debug folder found in the same location as the SDL2-2.0.4 folder. Then go to SDL2_image-2.0.1-lib-x84 and copy all 6 .dll files and paste them in the same Debug folder. Now, the prject should run fine.

##Issue With Syncing Project
Delete the SDF file or try backing up your work and delete then reclone project.

##Issue With Merging Conflict
Is there a SDF file you're trying to upload?

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
As we have a lot of work this week, we decided to focus our project on researching how other games have approached a similiar target audience. This is required as part of our commersial awareness but it gave us some ideas on how to approach level layout and game introduction. We looked into our target audience specificly their age range and what issues relate to them which can be implemented into our game.

An issue for this week was that we didn't allocate enough time to coding our project so it hasn't changed much from last week. Also, more commits are recommended to improve professional practise. We seem to work primarily when we are avaliable to meet in person at the moment so we can pair program and overcome challanges with the program together.

##The Second Sprint Review
With Agile practise, we are responsible for taking our own user stories from the Trello board. However due to our recent workload and scheduling issues, we didn't achieve all the user stories we had anticipated however we did complete some user stories which are crucial to our commercial and target audience research.

We have discussed the lack of productivity over this sprint and have taken steps to ensure that for the further sprints we can work around scheduling issues and other assignments. We have decided to use Skype screen share and to use Facebook chat to schedule pair programming as it notifies members of messages whereas we found with Slack it was easy to miss messages.

##Week 5-7 - Notepad Map Design Implementation
###Task completed by: Thomas and Sam (Pair programming) 
Over the holidays, we attempted to continue working on our group project while working on our individual projects. Using Skype and Google Hangouts to screen share. This was effective in our pair programming practise.  

In order to create our levels, we wanted to use a swtich case with a text file to describe and give information to the texture renderer. This would then allow for easy level design. This method would also allow for easily collision detection and tiled levels.

The main obsticle with this method is that we have struggled to overcome an error in our code. In order to overcome this error, we should submit a pull request and ask for additional advice from our lecturers.

#Week 8 - Tiled Level Layout Implemented
###Task completed by: Thomas and Sam (Pair programming) 
Having discussed the error the was interuptting our work with our lecturers, we found that the error was an issue with a circuluar include of headers where SoftFox.h was included in Level.h and vice versa. This has taught our group more about C++/SDL and how to manage and maintain the includes. 

#Week 9 - Platform Dirt Uses Level
##Task completed by: Thomas and Sam (Pair programming) 
After implementing our working map layout based on a tixt file, we started to created more level layouts. As the level generation was simple to implement changes, this meant we could create more levels quickly. We also amde the player and hunter spawn into the game using the text file.

The main obsticle this week as been our lack of knowledge with Github, as we struggled to uploaded, merge and maintain branches of code. This slowed production to a stop and took a long time to fix. This also lead to a fear of losing work from attempting to fix the problem. We overcame this obsticle by approaching our lecturers and presenting the problem. They were able to fix this after some attempts and production was able to continue.

#The Third Sprint Review
The project owner commented on our use of Trello, and how to improve the wording of our user stories. We were also given advice on how to include investor focused user stories into our Trello board, such as including market research.

The final scope of the project was questioned and the project manager wanted to focus our attention to the main user stories to complete in the final weeks. This has influenced our next sprint plan and what user stories to work on.

![alt text][End_of_third_sprint] 

[End_of_third_sprint]: https://github.com/sw180283/SoftFox/blob/master/Trello/Third_Complete_Sprint_Plan.jpg "End Of Third Sprint"

#Week 10 - Working on our own elements to the game
During this week of the task we all had our coding task two elements of the game to work on in order bring them into the game so that we can have a shipable product. I worked on the hunter mechanic for the group project in order to try and get him loading in and functional, while sam worked on her collision detection in order to give objects in game mass and create gravity.Dean also has his coding task two of mushroom collection to allow players in game to collect mushrooms in game.

During this week the main obsticle was we did not communicate much as we our own coursework. During this period we did not skype but we did keep track of what we were doing by messaging. This meant that we didnt work on the core game much but as we were working on our own components the game still made progress.
