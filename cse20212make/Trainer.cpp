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
#include <vector>
#include "Item.h"
#include "Location.h"
#include "Trainer.h"
#include "Potion.h"
#include "BoardPiece.h"
using namespace std;

//constructor, creates blank trainer
Trainer::Trainer()
{
		return;
}

//constructor, creates trainer, with name of the string and boardpiece passed in
Trainer::Trainer(string name, BoardPiece p,Sprite s)
{
	my_name = name;
	my_piece = p;
	my_sprite=s;
}

//adds a pokemon to a party, adds to pc if party is full
void Trainer::addToParty(Pokemon p)
{
	if(my_party.size()>5)
	{
		my_pokemon.push_back(&p);
		return;
	}
	my_party.push_back(p);
}

//removes pokemon form party
void Trainer::removeFromParty(int remove)
{
	my_party.erase(my_party.begin() + remove);
}

//removes pokemon form the pc
void Trainer::removeFromPC(int remove)
{
	my_pokemon.erase(my_pokemon.begin() + remove);
}

//adds pokemon to the pc
void Trainer::addToPC(Pokemon *p)
{
	my_pokemon.push_back(p);
}

//catches a pokemon
void Trainer::catchPokemon(Pokemon p)
{
	addToParty(p);
}

//returns the pokemon with the index of the int passed, and the in the vector passed
Pokemon Trainer::getPokemon(int index, vector<Pokemon> vec)
{
	return vec[index];
}

//returns the pokemon in the party with that index
Pokemon Trainer::getPokemon(int num)
{
	return my_party[num];
}

//sets teh pokemon at the index of the first int to have the hp of the second int
void Trainer::swapPokemon(int num, int HP)
{
	my_party[num].setHP(HP);
}

//returns the number of pokemon that are avalible to fight (HP>0)
int Trainer::getNumPokemonAvalible()
{
	int count = 0;
	for (int i = 0; i < my_party.size(); i++)
	{
		if (my_party[i].getHP() > 0)
			count++;
	}
	return count;
}

//prints the pokemon and their hp in the party
void Trainer::printPokemon()
{
	int i = 0;
	for (i = 0; i < my_party.size(); i++)
	{
		cout << i << ")" << " ";
		my_party[i].oppPrint();
	}
}

//returns teh vector of the party
vector<Pokemon> Trainer::getParty()
{
	return my_party;
}

//returns the vector storing the potions
vector<Potion*> Trainer::getPotions()
{
	return my_potions;
}

//prints out all the potions a trainer has
void Trainer::printPotions()
{
	int i = 0;
	string name = "";
	for (i = 0; i < my_potions.size(); i++)
	{
		name = my_potions[i]->getName();
		cout << i << ") " << name << endl;
	}
}

//adds a potion to the users bag
void Trainer::addPotion(Potion* potion)
{
	my_potions.push_back(potion);
}

//uses the potion at the index of the int on the pokemon passed in
void Trainer::usePotion(int i, Pokemon p)
{
	Potion item = *my_potions[i];
	item.use(p);
	my_potions.erase(my_potions.begin() + i);
}

//returns the trainer's name
string Trainer::getName()
{
	return my_name;
}

//sets the boardPiece of the trainer to the passed in value
void Trainer::setBoardPiece(BoardPiece p)
{
	my_piece = p;
}

// returns the boardpiece of the traienr
BoardPiece& Trainer::getBoardPiece()
{
	return my_piece;
}

//updates the xp of the pokeon at the first int index to the second in
void Trainer::updateXP(int num, int XP)
{
	my_party[num].setXP(XP);
}

//returns the sprite
Sprite Trainer::getSprite()
{
	return my_sprite;
}

int Trainer::getFirstAvailablePokemon()
{
	for(int i = 0; i < my_party.size(); i++)
	{
		if(my_party[i].getHP() > 0)
			return i;
	}
}
