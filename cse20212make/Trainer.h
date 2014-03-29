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

using namespace std;



class Trainer

{

public:

	Trainer();

	void addToParty(Pokemon);

	void removeFromParty(int);

	void removeFromPC(int);

	void addToPC(Pokemon);

	void catchPokemon(Pokemon);

	Pokemon getPokemon(int, vector<Pokemon>);

private:

	vector<Pokemon> my_party;

	vector<Pokemon> my_pokemon;

};





#endif
