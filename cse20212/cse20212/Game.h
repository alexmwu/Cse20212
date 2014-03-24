/* Pokemon Project
Alex Hansen
Game.h

Game Class.
Basically the running file for the entire game
*/

#ifndef GAME_H
#define GAME_H
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
	Game();
	void initilizePokemon();
	void initilizeSprites();
	void drawMap();
	Sprite findSprite(string);
	void printMap();
	void initilizeTypes();
	void initilizeTypeChart();
	double getTypeStrength(Type, Type);
	Type getType(string);
	void initilizeMoves();
	void battle(Pokemon, Pokemon);
	Move getMove(string);
	void test();
private:
	vector<Pokemon> my_pokemon;
	vector<Sprite> my_sprites;
	vector<vector<Sprite> > my_map; //change to boardPieces
	vector<Type> my_types;
	vector<vector<char> > my_typeChart;
	vector<Move> my_moves;
	vector<Pokeball> my_pokeballs;
};



#endif