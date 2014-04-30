#include <stdlib.h>
#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Pokeball.h"
#include "Item.h"
using namespace std;

//creates a blank pokeball
Pokeball::Pokeball()
{
	return;
}

//creates a pokeball with the string name, and int strength
Pokeball::Pokeball(string name, int s)
{
	my_name = name;
	my_strength = s;
}

//sets teh strength to the passed value
void Pokeball::setStrength(int s)
{
	my_strength = s;
}

//returns the strength of the pokeball
int Pokeball::getStrength()
{
	return my_strength;
}

//determines if the pokemon will be caught will the given pokeball, and pokemon passed in
int Pokeball::canCatch(Pokemon p)
{
	if (!p.isWild())
	{
		//cout << "Cannot capture other trainer's Pokemon!" << endl;
		return -1;
	}
	double f[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	f[0] = 100 - p.getLevel();
	f[1] = (1.0 - 1.0*p.getHP() / p.getMaxHP()) * 200;
	f[2] = rand() % 200;

	double prob = f[0] + f[1] + f[2];
	if (prob >= 250)
	{
	//	cout << p.getName() << " was successfully caught!" << endl;
		return 1;
	}
	//cout << "Oh no, it broke free!" << endl;
	return 0;
}
