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
	void initializePokemon();
	void initializeSprites();
	void drawMap(); //initializes boardpieces
	Sprite getSprite(string);
	void printMap();
	void initializeTypes();
	void initializeTypeChart();
	double getTypeStrength(Type, Type);
	Type getType(string);
	void initializeMoves();
	
	pair<int, int> battle(Pokemon*, Pokemon*);
	void battle(Trainer*, Trainer*);	//need to change to trainer v trainer
	Pokemon getPokemon(string);
	void initializeTrainers();
	void printPokemon();
	Move getMove(string);
	void test();
	void play();		//play
	void displayBattle(Pokemon,Pokemon);	//display battling Pokemon
	void displayMap();		//display map graphically
	void displayTrainers();		//display trainers on map
	void applySurface(int,int, SDL_Surface*, SDL_Surface*, SDL_Rect* = NULL);	//apply surface to screen
	void whiteScreen();	//make screen white
	
private:
	vector<Pokemon> my_pokemon;
	vector<Sprite> my_sprites;
	vector<vector<BoardPiece> > trainer_map;
	vector<vector<BoardPiece> > my_map; 
	vector<Type> my_types;
	vector<vector<char> > my_typeChart;
	vector<Move> my_moves;
	vector<Pokeball> my_pokeballs;
	vector<Trainer> my_trainers;

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
