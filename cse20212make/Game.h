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
#include <time.h>

using namespace std;

class Game
{
public:
	Game(int,int,int,int);	//screen width, screen height, screen bpp
	void initializeSDL();
	void quitSDL();
	void initializePokemon();
	void initializeSprites();
	void drawMap(); //initilizes boardpieces
	Sprite findSprite(string);
	void printMap();
	void initializeTypes();
	void initializeTypeChart();
	double getTypeStrength(Type, Type);
	Type getType(string);
	void initializeMoves();
	void battle(Pokemon, Pokemon);
	Move getMove(string);
	void test();
	void play();		//play
private:
	vector<Pokemon> my_pokemon;
	vector<Sprite> my_sprites;
	vector<vector<BoardPiece> > my_map; //change to boardPieces
	vector<Type> my_types;
	vector<vector<char> > my_typeChart;
	vector<Move> my_moves;
	vector<Pokeball> my_pokeballs;

	SDL_Event event;	//user event (like arrow key being pressed)
	SDL_Surface *screen;	//screen being displayed on
	SDL_Surface *map;	//map being played on
	SDL_Surface *trainers;	//trainers being displayed
	int screen_width;	//width of screen
	int screen_height;	//height of screen
	int screen_bpp;	//bits per pixel of screen (e.g., 32 for 32 bit color)
	int move_speed;		//how fast user can move keys
};
#endif
