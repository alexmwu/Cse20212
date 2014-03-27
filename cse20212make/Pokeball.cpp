#include <stdlib.h>
#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Pokeball.h"
using namespace std;

Pokeball::Pokeball()
{
	return;
}

Pokeball::Pokeball(int s)
{
	my_strength = s;
}

void Pokeball::setStrength(int s)
{
	my_strength = s;
}

int Pokeball::getStrength()
{
	return my_strength;
}

int Pokeball::canCatch(Pokemon p)
{
	if (!p.isWild())
	{
		cout << "Cannot capture other trainer's Pokemon!" << endl;
		return 0;
	}
	double f[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	f[0] = 100 - p.getLevel();
	f[1] = (1.0 - 1.0*p.getHP() / p.getMaxHP()) * 200;
	f[2] = rand() % 200;

	double prob = f[0] + f[1] + f[2];
	if (prob >= 250)
	{
		cout << p.getName() << " was successfully caught!" << endl;
		return 1;
	}
	cout << "Oh no, it broke free!" << endl;
	return 0;
}