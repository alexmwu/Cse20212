/* Pokemon Project
Alex Hansen
Potion.cpp

Potion Class.
Class extedning item, used for an item to heal HP ~ Potion
*/

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Item.h"
#include "Potion.h"

//creates a blank Potion object
Potion::Potion()
{
	return;
}

//creates a potion with the given name, if it is a battle item, outside item, and the strength
Potion::Potion(string name, int battle, int outside, int strength) : Item(name, battle, outside)
{
	my_strength = strength;
}

//uses the item on the given pokemon
int Potion::use(Pokemon p)
{
	if (p.getHP() > 0)
		p.setHP(p.getHP() + my_strength);
	else
		cout << "That Pokemon has fainted, a potion cannot revive it." << endl;
	return 1;
}

//returns the name of the potion
string Potion::getName()
{
	return my_name;
}

