/* Pokemon Project
Alex Hansen
Item.h

item Class.
abstract class that will be used for portions, and elixers and such, as well as pokeballs.
*/

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Pokeball.h"

using namespace std;

Item::Item()
{
	return;
}

Item::Item(string name, int battle, int outside)
{
	my_name = name;
	my_battleItem = battle;
	my_outsideItem = outside;
}

void Item::setName(string name)
{
	my_name = name;
}

void Item::setBattle(int battle)
{
	my_battleItem = battle;
}

void Item::setOutside(int outside)
{
	my_outsideItem = outside;
}

string Item::getName()
{
	return my_name;
}

int Item::getBattle()
{
	return my_battleItem;
}

int Item::getOutside()
{
	return my_outsideItem;
}