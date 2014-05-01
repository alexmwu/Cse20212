/* Pokemon Project
Alex Hansen
Trainer.h

Trainer Class.
stores a list of pokemon objects that can be used in the Pokemon interfaces
*/

#ifndef TRAINER_H
#define TRAINER_H
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Location.h"
#include "Sprite.h"
#include "Pokemon.h"
#include <vector>
#include "Item.h"
#include "Location.h"
#include "Potion.h"
#include "BoardPiece.h"
using namespace std;

class Trainer
{
public:
	Trainer();					//constructor, creates blank trainer
	Trainer(string, BoardPiece, Sprite);			//constructor, creates trainer, with name of the string and boardpiece passed in
	//void addToParty(Pokemon*);
	void addToParty(Pokemon);			//adds a pokemon to a party, adds to pc if party is full
	void removeFromParty(int);			//removes pokemon from party
	void removeFromPC(int);				//removes pokemon from the pc
	void addToPC(Pokemon*);				//adds pokemon to the pc
	void catchPokemon(Pokemon);			//catches a pokemon
	Pokemon getPokemon(int, vector<Pokemon>);	//returns the pokemon with the index of the int passed, and the in the vector passed
	Pokemon getPokemon(int);			//returns the pokemon in the party with that index
	void swapPokemon(int, int);			//sets teh pokemon at the index of the first int to have the hp of the second int
	int getNumPokemonAvalible();			//returns the number of pokemon that are avalible to fight (HP>0)
	void printPokemon();				//prints the pokemon and their hp in the party
	vector<Pokemon> getParty();			//returns teh vector of the party
	vector<Potion*> getPotions();			//returns the vector storing the potions
	void printPotions();				//prints out all the potions a trainer has
	void addPotion(Potion *);			//adds a potion to the users bag
	void usePotion(int, Pokemon);			//uses the potion at the index of the int on the pokemon passed in
	string getName();				//returns the trainer's name
	void setBoardPiece(BoardPiece);			//sets the boardPiece of the trainer to the passed in value
	BoardPiece& getBoardPiece();			// returns the boardpiece of the traienr
	void updateXP(int, int);			//updates the xp of the pokeon at the first int index to the second in
	Sprite getSprite();				//returns the sprite
	int getFirstAvailablePokemon();			//gets the index of the first pokemon avalible
	void setName(string);				//sets the name of the trainer
private:
	vector<Pokemon> my_party;			//vector of pokemon in party
	vector<Pokemon*> my_pokemon;			//vector of pokemon in pc
	vector<Potion*> my_potions;			//vector of potions in trainers bag
	string my_name;					//trainers name
	BoardPiece my_piece;				//trainers board piece
	Sprite my_sprite;
};
#endif
