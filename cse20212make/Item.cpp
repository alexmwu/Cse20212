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

//black constructor, creates empty object
Item::Item()
{
	return;
}

//creates object with the given name, ints are if its a battle item and if its an outside item
Item::Item(string name, int battle, int outside)
{
	my_name = name;
	my_battleItem = battle;
	my_outsideItem = outside;
}

//sets the items name
void Item::setName(string name)
{
	my_name = name;
}

//sets if the item is a battle item
void Item::setBattle(int battle)
{
	my_battleItem = battle;
}

//sets if the item is an outside item
void Item::setOutside(int outside)
{
	my_outsideItem = outside;
}

//returns the value of the name
string Item::getName()
{
	return my_name;
}

//returns if the item can be used in battle
int Item::getBattle()
{
	return my_battleItem;
}

//returns if the item can be used outside
int Item::getOutside()
{
	return my_outsideItem;
}
