/* Pokemon Project

Alex Hansen

Trainer.h



Trainer Class.

stores a list of pokemon objects that can be used in the Pokemon interfaces

*/



#include <stdlib.h>

#include <iostream>

#include <string>

#include "Location.h"

#include "Sprite.h"

#include "Pokemon.h"

#include "Trainer.h"

#include <vector>

using namespace std;





Trainer::Trainer()

{

	return;

}





void Trainer::addToParty(Pokemon p)

{

	int remove = -1;

	Pokemon temp;

	if (my_party.size() == 6)

	{

		cout << "Which Pokemon would you like to remove from your party" << endl;

		while (remove < 0)

		{

			cin >> remove;

			if (remove > 5 || remove < 0)

			{

				cout << "Invalid Pokemon, try again." << endl;

				remove = -1;

			}

		}

		temp = getPokemon(remove, my_party);

		removeFromParty(remove);

		addToPC(temp);

	}

	else

		my_party.push_back(p);

}



void Trainer::removeFromParty(int remove)

{

	my_party.erase(my_party.begin() + remove);

}



void Trainer::removeFromPC(int remove)

{

	my_pokemon.erase(my_pokemon.begin() + remove);

}



void Trainer::addToPC(Pokemon p)

{

	my_pokemon.push_back(p);

}



void Trainer::catchPokemon(Pokemon p)

{

	addToParty(p);

}



Pokemon getPokemon(int index, vector<Pokemon> vec)

{

	return vec[index];

}


