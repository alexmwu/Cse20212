Cse20212 - Pokemon
Alex Hansen
Alex Wu
========
This program is an recreation of Pokemon, using 3rd generation sprites. The program has two towns and a long route between the two towns. In the second town there is a gym with trainers in it. The way the program was designed, the game can be expanded and changed easily by simply making the appropriate changes to the text files that the game reads from. 

DOWNLOADING AND COMPILING:
To download the program the user should go to the GitHub Repository and clone the project.
Link : https://github.com/ahansen3/Cse20212.git

Once the program is cloned, the user should go into the directory "Cse20212" then into the directory "cse20212make." From here the user simply needs to type the make command and the compiler will compile all the objects and create the executable for the user to use. When compilation is complete type "./pokemongame" into the terminal and the game will open in a new window. 



GAMEPLAY:
Once in the game, the user will notice they are blue the trainer in the middle of the screen. Use the arrow keys to control the movement. If you walk into tall grass there is a chance that a wild Pokemon will attack the user. Or if you walk in the path of a trainer, they may challenge you to a battle. 

Either of these occurrences will trigger the battle sequence to start. Here the user will have their Pokemon battle the opposing Pokemon. Simply following the prompts in the battle screen will help guide the user through the battle sequence. 

When a Pokemon is defeated, the winning Pokemon will be allocated some experience points (XP) which will cause it to level up and increase in strength. Careful don't let any Pokemon run out of hit points (HP) or that Pokemon will become unusable.



DOCUMENTATION:
In the repository home directory there is a folder named "Documentation." In that folder you will find the UML Diagrams for each of the major classes used, as well as two interaction diagrams. The simple interaction diagram shows how the objects interact on a basic level, while the complex diagram shows which objects use any other object in all occurrences. 

within the "cse2012make" directory there are two folders (in addition to all the c++ code files). One file (images) contains all the sprite sheets and images the program will reference. In the "text" file, you will find all the text files that the program will read off of to create all the Pokemon, Move, Type, and Trainer objects, along with all other objects in the game. You will also see the files that create things like the map and the location pairs for changing between places on the map (ie. environment to buildings).


BUGS:
The following are known bugs as well as improvements to the program that we would've liked to implement given more time.

-Sprite animation for movement

-Battle animations

-When you are standing on a door, you cannot walk through the walls - this is intentional

-can walk through trainers

*FIXED:Trainers will continuously battle you upon each step. 

-Trainers disappear when they are defeated: they are removed from game

-Unable to close window during battle scene

-FIXED: Unable to change move selection once you choce one

-FIXED: Moves are not displayed in the window

-Pokemon HP of avalible pokemon not displayed in the window

-FIXED: HP bar doesn't display HP properly

-FIXED: Battle Dialog is not working

-Pokemon healed in between battles

-FIXED: seg faults if all pokemon faint and for wild pokemon battles

-seg fault when Blastoise uses surf on 2nd gym trainer
