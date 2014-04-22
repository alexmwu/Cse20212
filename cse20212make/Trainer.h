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
using namespace std;

class Trainer
{
public:
	Trainer();
	Trainer(string, Location);
	//void addToParty(Pokemon*);
	void addToParty(Pokemon);
	void removeFromParty(int);
	void removeFromPC(int);
	void addToPC(Pokemon*);
	void catchPokemon(Pokemon);
	Pokemon getPokemon(int, vector<Pokemon>);
	Pokemon getPokemon(int);
	void swapPokemon(int, int);
	int getNumPokemonAvalible();
	void printPokemon();
	vector<Pokemon> getParty();
	vector<Potion*> getPotions();
	void printPotions();
	void addPotion(Potion *);
	void usePotion(int, Pokemon);
	string getName();
	void setLcoation(Location);
	Location getLocation();
private:
	vector<Pokemon> my_party;
	vector<Pokemon*> my_pokemon;
	vector<Potion*> my_potions;
	string my_name;
	Location my_loc;
};
#endif
