/* Pokemon Project
Alex Hansen
Potion.h

Potion Class.
Class extending item, used for an item to heal HP ~ Potion
*/

#ifndef POTION_H
#define POTION_H
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Item.h"
#include "Pokemon.h"

using namespace std;

class Potion : public Item
{
public:
	Potion();				//creates a blank Potion object
	Potion(string, int, int, int);		//creates a potion with the given name, if it is a battle item, outside item, and the strength
	void setStrength(int);			//sets the strength of the potion inherited from item
	int getStrength();			//returns the strength inherited from item
	int use(Pokemon);			//uses the item on the given pokemon
	string getName();			//returns the name of the potion
private:
	int my_strength;			//stores the strength of the potion
};
#endif
