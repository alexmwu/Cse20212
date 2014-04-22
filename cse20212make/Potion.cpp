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

Potion::Potion()
{
	return;
}

Potion::Potion(string name, int battle, int outside, int strength) : Item(name, battle, outside)
{
	my_strength = strength;
}

int Potion::use(Pokemon p)
{
	if (p.getHP() > 0)
		p.setHP(p.getHP() + my_strength);
	else
		cout << "That Pokemon has fainted, a potion cannot revive it." << endl;
	return 1;
}

string Potion::getName()
{
	return my_name;
}
