/* Pokemon Project
Alex Hansen
Game.h

Game Class.
Basically the running file for the entire game
*/

#ifndef GAME_H
#define GAME_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include "BoardPiece.h"
#include "Location.h"
#include "Pokemon.h"
#include <fstream>
#include <vector>
#include "Sprite.h"
#include <sstream>
#include <iterator>
#include "Type.h"
#include "Move.h"
#include "Pokeball.h"
#include "Timer.h"
#include <time.h>
#include "Item.h"
#include "Potion.h"
#include "Trainer.h"

using namespace std;

class Game
{
public:
	Game(int,int,int,int,int);	//screen width, screen height, screen bpp, move speed, game fps
	void initializeSDL();		//initializes SDL systems, will also load sprite sheets
	void initializeSpriteSheets();	//intialize sprite sheets to SDL_Surfaces
	void quitSDL();		//frees all SDL systems and quits SDL
	SDL_Surface *loadImage(string);	//loads sprite sheets
	SDL_Surface *switchSheet(int);		//switches the sprite sheet filename (string) for the pointer to the sheet
	void initializePokemon(); 	//reads in data from text file and creates pokemon objects from it
	void initializeSprites(); 	//reads in data from text file and creates Sprite objects from it
	void drawMap(); 		//initializes boardpieces
	Sprite getSprite(string); 	//returns the sprite with the name of the string parameter
	void printMap(); 		//prints out the map with just sprite names in the terminal window
	void initializeTypes(); 	//reads in data from text file and creates Types objects from it
	void initializeTypeChart(); 	//reads in data from text file and creates a type chart used for strength from it
	double getTypeStrength(Type, Type); //given the two types returns the effectiveness of the first against the second(superEffective =2, normal =1, not veery effective =.5, not effectiv =0)
	Type getType(string);		//returns the type who has the name of the string input
	void initializeMoves(); 	//reads in data from text file and creates pokemon objects from it
	void initializeLocationPairs(); //Initializes the location pairs for movement between enveironment and buidlings
	
	pair<int, int> battle(Pokemon*, Pokemon*); 	//runs a battle sequece between two pokemon
	void battle(Trainer*, Trainer*);		//need to change to trainer v trainer, in turn it runs the pokemon v pokemon function for each match up
	Pokemon getPokemon(string); 			//returns the pokemon whose name is the same as the string
	void initializeTrainers(); 			//reads in data from text file and creates trainers objects from it
	void printPokemon(); 				//pritns all the pokemon that have been instasiated
	Move getMove(string); 				//returns the move that has the name of the string input
	Sprite charToSprite(char); 
	void textToSDL(string,int, int, int,int);		//string of text to display, width of text box, x,y locations, and gap between letters(pixels)
	void test(); 					//blank function used for testing
	void play();					//play
	void displayBar(Sprite,Sprite,string);		//display the battle bars
	void displayMap();				//display map graphically
	void displayTrainers();				//display trainers on map	
	void applySurface(int,int, SDL_Surface*, SDL_Surface*, SDL_Rect* = NULL);	//apply surface to screen
	void whiteScreen();				//make screen white
	BoardPiece getMapPiece(int, int); 		//returns the BoardPice at the corresponding location. 
	void interact(Location, Sprite); 		//will allow the user to interact with sprites.
	Location getLocationComplement(Location);	 //returns the complement location to the passed location
	void wildPokemon(); 				//function for when a wild Pokemon attacks
	void checkTrainerSight(Location);		//checks to see if trainers can see the user after each step
	void moveTrainer(Trainer, Location);		//function that will move the trainers to attack the user

	
private:
	vector<Pokemon> my_pokemon; 			//list of all pokemon in the game
	vector<Sprite> my_sprites; 			//list of all the sprites avalible to be used
	vector<vector<BoardPiece> > trainer_map; 
	vector<vector<BoardPiece> > my_map; 		//map of boardpieces that will be displayed and played on
	vector<Type> my_types; 				//list of all the types available in the game
	vector<vector<char> > my_typeChart; 		//chart to be used to determine stengths and effectivenss between types
	vector<Move> my_moves; 				//stores all the moves avalible in the game
	vector<Pokeball> my_pokeballs; 			//list of all pokeballs avalible
	vector<Trainer> my_trainers; 			//list of all the trainers in the game
	vector<pair<Location, Location> > my_locationPairs; //list of all the location pairs, used to switch between buildings and the enveironment

	SDL_Surface *battlepokemon;	//in-battle pokemon sprites
	SDL_Surface *battlemenu;	//battle menu sprite sheet
	SDL_Surface *buildings;		//buildings sprite sheet
	SDL_Surface *environment;	//environment sprite sheet
	SDL_Surface *envpokemon;	//sprite sheet for pokemon on map
	SDL_Surface *heroes;		//heroes of game
	SDL_Surface *misc;		//miscellaneous sprite sheet
	SDL_Surface *npcs;		//npc sprite sheet
	SDL_Surface *pokemenu;		//sprite sheet for pokemon menu


	SDL_Event event;	//user event (like arrow key being pressed)
	
	SDL_Surface *battlescene;	//battle scene
	SDL_Surface *screen;	//screen being displayed on
	SDL_Surface *map;	//map being played on
	SDL_Surface *trainers;	//trainers being displayed
	int screen_width;	//width of screen
	int screen_height;	//height of screen
	int screen_bpp;	//bits per pixel of screen (e.g., 32 for 32 bit color)
	
	int frames_per_second;	//fps of game
	int frame_cap;		//framerate cap
	Timer fps;	//timer object to check frame rate
	
	int move_speed;		//how fast user can move keys
	int is_battle;		//is pokemon in battle
};
#endif
