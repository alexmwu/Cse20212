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
using namespace std;

Trainer::Trainer()
{
		return;
}

Trainer::Trainer(string name, Location loc)
{
	my_name = name;
	my_loc = loc;
}


//void Trainer::addToParty(Pokemon *p)
//{
//	int remove = -1;
//	Pokemon *temp;
//	if (my_party.size() == 6)
//	{
//		cout << "Which Pokemon would you like to remove from your party" << endl;
//		while (remove < 0)
//		{
//			cin >> remove;
//			if (remove > 5 || remove < 0)
//			{
//				cout << "Invalid Pokemon, try again." << endl;
//				remove = -1;
//			}
//		}
//		temp = getPokemon(remove, my_party);
//		removeFromParty(remove);
//		addToPC(temp);
//	}
//	else
//		my_party.push_back(p);
//}

void Trainer::addToParty(Pokemon p)
{
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

void Trainer::addToPC(Pokemon *p)
{
	my_pokemon.push_back(p);
}

void Trainer::catchPokemon(Pokemon p)
{
	addToParty(p);
}

Pokemon Trainer::getPokemon(int index, vector<Pokemon> vec)
{
	return vec[index];
}

Pokemon Trainer::getPokemon(int num)
{
	return my_party[num];
}

void Trainer::swapPokemon(int num, int HP)
{
	my_party[num].setHP(HP);
}

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

void Trainer::printPokemon()
{
	int i = 0;
	for (i = 0; i < my_party.size(); i++)
	{
		cout << i << ")" << " ";
		my_party[i].oppPrint();
	}
}

vector<Pokemon> Trainer::getParty()
{
	return my_party;
}

vector<Potion*> Trainer::getPotions()
{
	return my_potions;
}

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

void Trainer::addPotion(Potion* potion)
{
	my_potions.push_back(potion);
}

void Trainer::usePotion(int i, Pokemon p)
{
	Potion item = *my_potions[i];
	item.use(p);
	my_potions.erase(my_potions.begin() + i);
}

string Trainer::getName()
{
	return my_name;
}

void Trainer::setLcoation(Location loc)
{
	my_loc = loc;
}

Location Trainer::getLocation()
{
	return my_loc;
}